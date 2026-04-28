'''
made by possible 
Treap(Tree+Heap, a.k.a PBDS) Structure
'''

import sys
import random
from collections import Counter

class Node:
    __slots__ = ['key', 'priority', 'count', 'size', 'left', 'right']

    def __init__(self, key):
        self.key = key
        self.priority = random.getrandbits(32) 
        self.count = 1  
        self.size = 1   
        self.left = None
        self.right = None

class Treap:
    def __init__(self, iterable=None, duplication=0):
        self.root = None
        self.duplication = duplication
        if iterable is not None:
            self._build_from_iterable(iterable)

    def _build_from_iterable(self, iterable):
        if not iterable: return

        counts = Counter(iterable)
        sorted_keys = sorted(counts.keys())
        if not sorted_keys: return

        nodes = []
        for k in sorted_keys:
            node = Node(k)
            node.count = counts[k] if self.duplication else 1
            nodes.append(node)

        stack = []
        for node in nodes:
            last_popped = None
            while stack and stack[-1].priority < node.priority:
                last_popped = stack.pop()
            node.left = last_popped
            if stack: stack[-1].right = node
            stack.append(node)

        self.root = stack[0]
        self._update_all_sizes_iterative()

    def _update_all_sizes_iterative(self):
        if not self.root: return
        s1 = [self.root]
        s2 = []
        while s1:
            node = s1.pop()
            s2.append(node)
            if node.left: s1.append(node.left)
            if node.right: s1.append(node.right)
        while s2:
            node = s2.pop()
            ls = node.left.size if node.left else 0
            rs = node.right.size if node.right else 0
            node.size = node.count + ls + rs

    def _update(self, node):
        if node:
            ls = node.left.size if node.left else 0
            rs = node.right.size if node.right else 0
            node.size = node.count + ls + rs

    def _split(self, node, key):
        left_root, right_root = None, None
        left_curr, right_curr = None, None
        path = [] 
        curr = node
        while curr:
            path.append(curr)
            if curr.key <= key:
                if not left_root: left_root = curr
                else: left_curr.right = curr
                left_curr = curr
                curr = curr.right
                left_curr.right = None 
            else:
                if not right_root: right_root = curr
                else: right_curr.left = curr
                right_curr = curr
                curr = curr.left
                right_curr.left = None
        for p in reversed(path):
            self._update(p)
        return left_root, right_root

    def _merge(self, left, right):
        dummy = Node(0)
        parent = dummy
        is_left_child = False
        path = []
        while left and right:
            if left.priority > right.priority:
                path.append(left)
                if is_left_child: parent.left = left
                else: parent.right = left
                parent = left
                is_left_child = False 
                left = left.right
            else:
                path.append(right)
                if is_left_child: parent.left = right
                else: parent.right = right
                parent = right
                is_left_child = True 
                right = right.left
        remaining = left if left else right
        if is_left_child: parent.left = remaining
        else: parent.right = remaining
        for p in reversed(path):
            self._update(p)
        return dummy.right

    def add(self, key):
        curr = self.root
        path = []
        found = False
        while curr:
            path.append(curr)
            if key == curr.key:
                found = True
                break
            curr = curr.left if key < curr.key else curr.right
        if found:
            if self.duplication:
                curr.count += 1
                for p in reversed(path): self._update(p)
            return
        new_node = Node(key)
        left, right = self._split(self.root, key)
        self.root = self._merge(self._merge(left, new_node), right)

    def remove(self, key):
        curr = self.root
        path = []
        found = False
        while curr:
            path.append(curr)
            if key == curr.key:
                found = True
                break
            curr = curr.left if key < curr.key else curr.right
        if not found: return
        if curr.count > 1:
            curr.count -= 1
            for p in reversed(path): self._update(p)
        else:
            left, right = self._split(self.root, key - 0.5)
            _, right = self._split(right, key + 0.5)
            self.root = self._merge(left, right)

    def order_of_key(self, key):
        node = self.root
        ans = 0
        while node:
            if node.key == key:
                return ans + (node.left.size if node.left else 0)
            elif node.key > key: node = node.left
            else:
                ans += (node.left.size if node.left else 0) + node.count
                node = node.right
        return ans

    def __len__(self):
        return self.root.size if self.root else 0

    def __contains__(self, key):
        node = self.root
        while node:
            if key == node.key: return True
            node = node.left if key < node.key else node.right
        return False

    def __getitem__(self, k):
        if k < 0: k += len(self)
        if k < 0 or k >= len(self): return None
        node = self.root
        while node:
            left_size = node.left.size if node.left else 0
            if k < left_size: node = node.left
            elif k < left_size + node.count: return node.key
            else:
                k -= (left_size + node.count)
                node = node.right
        return None

    def __iter__(self):
        stack = []
        node = self.root
        while stack or node:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                for _ in range(node.count): yield node.key
                node = node.right

    def lower_bound_iter(self, l):
        stack = []
        node = self.root
        while stack or node:
            if node:
                if node.key >= l:
                    stack.append(node)
                    node = node.left
                else: node = node.right
            else:
                node = stack.pop()
                if node.key >= l:
                    for _ in range(node.count): yield node.key
                node = node.right

    def range_iter(self, l, r):
        stack = []
        node = self.root
        while stack or node:
            if node:
                if node.key >= l:
                    stack.append(node)
                    node = node.left
                else: node = node.right
            else:
                node = stack.pop()
                if node.key > r: break
                if node.key >= l:
                    for _ in range(node.count): yield node.key
                node = node.right

""" md 파일 형식임
메서드	기능	시간복잡도
add(x)	x를 container에서 추가	O(logN)
remove(x)	x를 container에서 삭제	O(logN)
order_of_key(x)	x보다 작은 원소의 갯수 반환	O(logN)
container[k], container[-k]	k번째로 작은 원소 반환	O(logN)
x in container	x가 container에 존재하는지 반환	O(logN)
len(os)	원소의 전체 갯수 반환	O(1)
for x in os	오름차순으로 정렬된 원소 순회	O(N)
lower_bound_iter(l)	l보다 크거나 같은 iterator 반환	탐색 O(log N), 순회 O(1)
range_iter(l, r)	[l, r] 사이의 iterator 반환	탐색 O(log N), O(r-l)
"""
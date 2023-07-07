#include <stdio.h>
#include <string.h>

int main() {
	int ntest;
	char buf[100];
	int i;
	int count1, count2;
    int len;
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%s", buf); // 1라인 입력
		count1 = count2 = 0;
        len = strlen(buf);
		// 문자열을 모두 검사해서
        if (buf[0] == ')' || buf[len - 1] == '(')
            printf("NO\n");
        else {
            for (i = 0; i < len; i++) {
                // ( 갯수와 ) 갯수를 count하고
                buf[i] == '(' ? count1++ : count2++;
                if (count1 - count2 == -1) break;
            }
    		// count1 count2 를 비교하여 판단
            if (count1 == count2) printf("YES\n");
            else printf("NO\n");
        }
	}
}
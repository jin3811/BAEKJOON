import java.util.*;
import java.io.*;

class Pair implements Comparable<Pair> {
    public int destination, distance;
    public Pair() { this(0,0); }
    public Pair(int destination, int distance) {
        this.destination = destination;
        this.distance = distance;
    }

    @Override
    public int compareTo(Pair p) {
        return this.distance == p.distance ?
                this.destination - p.destination :
                this.distance - p.distance;
    }
}

public class Main {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    int n, m;
    List<Pair>[] graph;

    public static void main(String[] args) throws IOException {
        (new Main()).solve();
    }

    public Main() throws IOException {
        int a, b, c;
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        graph = new ArrayList[n + 1];

        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for(int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            graph[a].add(new Pair(b, c));
            graph[b].add(new Pair(a, c));
        }
    }

    private int[] dijkstra() {
        int[] dist = new int[n + 1];
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();

        for(int i = 0; i <= n; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        dist[1] = 0;
        pq.add(new Pair(1, 0));

        while(!pq.isEmpty()) {
            Pair cur = pq.poll();

            if (cur.distance > dist[cur.destination]) {
                continue;
            }

            for(Pair next : graph[cur.destination]) {
                if (dist[next.destination] > cur.distance + next.distance) {
                    pq.add(new Pair(next.destination, cur.distance + next.distance));
                    dist[next.destination] = cur.distance + next.distance;
                }
            }
        }
        return dist;
    }
    public void solve() {
        System.out.print(dijkstra()[n]);
    }
}
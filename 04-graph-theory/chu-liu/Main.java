import java.io.*;
import java.math.*;
import java.util.*;

// BEGIN
class ChuLiu {
    double solve(double[][] graph, int root) {
        int n = graph.length;
        double ret = 0;
        int[] in = new int[n];
        boolean[] used = new boolean[n];
        while (true) {
            boolean found = false;
            Arrays.fill(in, -1);
            for (int i = 0; i < n; ++ i) {
                if (i != root && !used[i]) {
                    for (int j = 0; j < n; ++ j) {
                        if (!used[j] && i != j) {
                            if (in[i] == -1 || graph[j][i] < graph[in[i]][i]) {
                                in[i] = j;
                            }
                        }
                    }
                }
            }
            boolean[] visit = new boolean[n];
            for (int i = 0; i < n; ++ i) {
                if (i != root && !used[i] && !visit[i]) {
                    int[] queue = new int[n];
                    int tail = 0;
                    int p = i;
                    for (; p != -1 && !visit[p]; p = in[p]) {
                        visit[queue[tail ++] = p] = true;
                    }
                    int head = 0;
                    while (head < tail && queue[head] != p) {
                        head ++;
                    }
                    if (head == tail) {
                        continue;
                    }
                    found = true;
                    for (int j = head; j < tail; ++ j) {
                        ret += graph[in[queue[j]]][queue[j]];
                        if (j != head) {
                            used[queue[j]] = true;
                            for (int k = 0; k < n; ++ k) {
                                if (!used[k] && graph[queue[j]][k] < graph[p][k]) {
                                    graph[p][k] = graph[queue[j]][k];
                                }
                            }
                        }
                    }
                    for (int j = 0; j < n; ++ j) {
                        if (j != p && !used[j]) {
                            for (int k = head; k < tail; ++ k) {
                                graph[j][p] = Math.min(graph[j][p], graph[j][queue[k]] - graph[in[queue[k]]][queue[k]]);
                            }
                        }
                    }
                }
            }
            if (!found) {
                break;
            }
        }
        for (int i = 0; i < n; ++ i) {
            if (!used[i] && i != root) {
                ret += graph[in[i]][i];
            }
        }
        return ret;
    }
}
// END

// Vector Compression
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2309
public class Main {
    double sqr(double x) {
        return x * x;
    }

    public void run() {
        try {
            int m = reader.nextInt();
            int n = reader.nextInt();
            double[][] vectors = new double[n + 1][m];
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < m; ++ j) {
                    vectors[i][j] = reader.nextDouble();
                }
            }
            double[] norms = new double[n + 1];
            for (int i = 0; i <= n; ++ i) {
                for (int j = 0; j < m; ++ j) {
                    norms[i] += sqr(vectors[i][j]);
                }
            }
            double[][] graph = new double[n + 1][n + 1];
            for (int i = 0; i <= n; ++ i) {
                for (int j = 0; j <= n; ++ j) {
                    if (norms[i] == 0) {
                        graph[i][j] = norms[j];
                    } else {
                        double dot = 0;
                        for (int k = 0; k < m; ++ k) {
                            dot += vectors[i][k] * vectors[j][k];
                        }
                        graph[i][j] = norms[j] - dot * dot / norms[i];
                    }
                }
            }
            writer.println(String.format("%.10f\n", new ChuLiu().solve(graph, n)));
        } catch (IOException ex) {
        }
        writer.close();
    }

    InputReader reader;
    PrintWriter writer;

    Main() {
        reader = new InputReader();
        writer = new PrintWriter(System.out);
    }

    public static void main(String[] args) {
        new Main().run();
    }

}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    InputReader() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = new StringTokenizer("");
    }

    String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    Integer nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    Double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

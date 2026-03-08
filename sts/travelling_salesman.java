import java.util.*;

public class travelling_salesman {

    static final int INF = (int)1e9;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
            for (int j = 0; j < n; j++) {
                adj.get(i).add(sc.nextInt());
            }
        }

        int N = 1 << n;
        ArrayList<ArrayList<Integer>> dp = new ArrayList<>();

        for (int mask = 0; mask < N; mask++) {
            dp.add(new ArrayList<>(Collections.nCopies(n, INF)));
        }

        // start from city 0
        dp.get(1).set(0, 0);

        for (int mask = 1; mask < N; mask++) {
            for (int u = 0; u < n; u++) {
                if ((mask & (1 << u)) == 0) continue;
                int cur = dp.get(mask).get(u);
                if (cur == INF) continue;

                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) != 0) continue;
                    int nmask = mask | (1 << v);
                    dp.get(nmask).set(
                        v,
                        Math.min(
                            dp.get(nmask).get(v),
                            cur + adj.get(u).get(v)
                        )
                    );
                }
            }
        }

        int ans = INF;
        for (int u = 0; u < n; u++) {
            ans = Math.min(ans, dp.get(N - 1).get(u) + adj.get(u).get(0));
        }

        System.out.println(ans);
        sc.close();
    }
}
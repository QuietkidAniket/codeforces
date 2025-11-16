import sys

# It might be beneficial to increase the recursion limit for certain environments, though not strictly necessary for this iterative solution.
# sys.setrecursionlimit(10**6)

class Solution:
  def solve(self, n: int, l: int, r: int) -> int:
    """
    Calculates the number of valid ZigZag arrays of length n with elements in [l, r].

    A ZigZag array satisfies:
    1. Each element is in [l, r].
    2. No two adjacent elements are equal.
    3. No three consecutive elements are strictly increasing or strictly decreasing.

    The method uses dynamic programming with prefix/suffix sum optimization.
    """
    MOD = 10**9 + 7

    # We use it to store the number of available integers.
    m = r-l+1
    
    # dp_incr[k] = number of valid sequences of current length ending with k,
    # where the last step was an increase (A[i-1] < A[i]).
    # dp_decr[k] = number of valid sequences of current length ending with k,
    # where the last step was a decrease (A[i-1] > A[i]).
    # We use 1-based indexing for values k, so the size is m+1.
    dp_incr = [0] * (m + 1)
    dp_decr = [0] * (m + 1)

    # Base case: length i = 2
    # For an array [j, k] of length 2:
    # If j < k, it's an increasing step ending in k. Number of choices for j is k-1.
    # If j > k, it's a decreasing step ending in k. Number of choices for j is m-k.
    for k in range(1, m + 1):
      dp_incr[k] = k - 1
      dp_decr[k] = m - k

    # Main DP loop for lengths i from 3 to n
    for i in range(3, n + 1):
      # --- Calculate prefix sums for the decreasing sequences of length i-1 ---
      # prefix_decr[k] = sum(dp_decr[j] for j=1 to k)
      prefix_decr = [0] * (m + 1)
      for k in range(1, m + 1):
        prefix_decr[k] = (prefix_decr[k-1] + dp_decr[k]) % MOD

      # --- Calculate suffix sums for the increasing sequences of length i-1 ---
      # suffix_incr[k] = sum(dp_incr[j] for j=k to m)
      # We use size m+2 for easier indexing (to avoid out-of-bounds for suffix_incr[k+1])
      suffix_incr = [0] * (m + 2)
      for k in range(m, 0, -1):
        suffix_incr[k] = (suffix_incr[k+1] + dp_incr[k]) % MOD

      # --- Calculate the new dp values for length i ---
      new_dp_incr = [0] * (m + 1)
      new_dp_decr = [0] * (m + 1)
      for k in range(1, m + 1):
        # To form an increasing step to k (..j < k), the previous step must
        # have been a decrease. We need to sum all dp_decr[j] where j < k.
        # This is exactly prefix_decr[k-1].
        new_dp_incr[k] = prefix_decr[k-1]

        # To form a decreasing step to k (..j > k), the previous step must
        # have been an increase. We need to sum all dp_incr[j] where j > k.
        # This is exactly suffix_incr[k+1].
        new_dp_decr[k] = suffix_incr[k+1]

      # Update dp tables for the next iteration
      dp_incr = new_dp_incr
      dp_decr = new_dp_decr

    # Final answer is the sum of all valid sequences of length n
    total_count = 0
    for k in range(1, m + 1):
      total_count = (total_count + dp_incr[k]) % MOD
      total_count = (total_count + dp_decr[k]) % MOD
      
    return total_count
<h2><a href="https://leetcode.com/problems/maximum-rows-covered-by-columns/">2397. Maximum Rows Covered by Columns</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> <code>m x n</code> binary matrix <code>mat</code> and an integer <code>cols</code>, which denotes the number of columns you must choose.</p>

<p>A row is <strong>covered</strong> by a set of columns if each cell in the row that has a value of <code>1</code> also lies in one of the columns of the chosen set.</p>

<p>Return <em>the <strong>maximum</strong> number of rows that can be <strong>covered</strong> by a set of </em><code>cols</code><em> columns.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2022/07/14/rowscovered.png" style="width: 250px; height: 417px;"></strong></p>

<pre><strong>Input:</strong> mat = [[0,0,0],[1,0,1],[0,1,1],[0,0,1]], cols = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong>
As shown in the diagram above, one possible way of covering 3 rows is by selecting the 0th and 2nd columns.
It can be shown that no more than 3 rows can be covered, so we return 3.
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2022/07/14/rowscovered2.png" style="width: 83px; height: 247px;"></strong></p>

<pre><strong>Input:</strong> mat = [[1],[0]], cols = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong>
Selecting the only column will result in both rows being covered, since the entire matrix is selected.
Therefore, we return 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 12</code></li>
	<li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
	<li><code>1 &lt;= cols &lt;= n</code></li>
</ul>
</div>
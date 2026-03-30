<h2><a href="https://leetcode.com/problems/incremental-even-weighted-cycle-queries">4114. Incremental Even-Weighted Cycle Queries</a></h2><h3>Hard</h3><hr><p>You are given a positive integer <code>n</code>.</p>

<p>There is an <strong>undirected</strong> graph with <code>n</code> nodes labeled from 0 to <code>n - 1</code>. Initially, the graph has no edges.</p>

<p>You are also given a 2D integer array <code>edges</code>, where <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>]</code> represents an edge between nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> with weight <code>w<sub>i</sub></code>. The weight <code>w<sub>i</sub></code> is either 0 or 1.</p>

<p>Process the edges in <code>edges</code> in the given order. For each edge, add it to the graph only if, after adding it, the sum of the weights of the edges in <strong>every</strong> cycle in the resulting graph is <strong>even</strong>.</p>

<p>Return an integer denoting the number of edges that are successfully added to the graph.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, edges = [[0,1,1],[1,2,1],[0,2,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2026/03/21/hmadizgovu.png" style="width: 168px; height: 150px;" /></p>

<ul>
	<li><code>[0, 1, 1]</code>: We add the edge between vertex 0 and vertex 1 with weight 1.</li>
	<li><code>[1, 2, 1]</code>: We add the edge between vertex 1 and vertex 2 with weight 1.</li>
	<li><code>[0, 2, 1]</code>: The edge between vertex 0 and vertex 2 (the dashed edge in the diagram) is not added because the cycle <code>0 - 1 - 2 - 0</code> has total edge weight <code>1 + 1 + 1 = 3</code>, which is an odd number.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, edges = [[0,1,1],[1,2,1],[0,2,0]]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2026/03/21/rbdgrefwok.png" style="width: 179px; height: 160px;" /></p>

<ul>
	<li><code>[0, 1, 1]</code>: We add the edge between vertex 0 and vertex 1 with weight 1.</li>
	<li><code>[1, 2, 1]</code>: We add the edge between vertex 1 and vertex 2 with weight 1.</li>
	<li><code>[0, 2, 0]</code>: We add the edge between vertex 0 and vertex 2 with weight 0.</li>
	<li>Note that the cycle <code>0 - 1 - 2 - 0</code> has total edge weight <code>1 + 1 + 0 = 2</code>, which is an even number.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= edges.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>]</code></li>
	<li><code>0 &lt;= u<sub>i</sub> &lt; v<sub>i</sub> &lt; n</code></li>
	<li>All edges are distinct.</li>
	<li><code>w<sub>i</sub> = 0 or w<sub>i</sub> = 1</code></li>
</ul>

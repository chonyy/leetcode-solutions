<h2><a href="https://leetcode.com/problems/design-excel-sum-formula/">631. Design Excel Sum Formula</a></h2><h3>Hard</h3><hr><div><p>Design the basic function of <strong>Excel</strong> and implement the function of the sum formula.</p>

<p>Implement the <code>Excel</code> class:</p>

<ul>
	<li><code>Excel(int height, char width)</code> Initializes the object with the <code>height</code> and the <code>width</code> of the sheet. The sheet is an integer matrix <code>mat</code> of size <code>height x width</code> with the row index in the range <code>[1, height]</code> and the column index in the range <code>['A', width]</code>. All the values should be <strong>zero</strong> initially.</li>
	<li><code>void set(int row, char column, int val)</code> Changes the value at <code>mat[row][column]</code> to be <code>val</code>.</li>
	<li><code>int get(int row, char column)</code> Returns the value at <code>mat[row][column]</code>.</li>
	<li><code>int sum(int row, char column, List&lt;String&gt; numbers)</code> Sets the value at <code>mat[row][column]</code> to be the sum of cells represented by <code>numbers</code> and returns the value at <code>mat[row][column]</code>. This sum formula <strong>should exist</strong> until this cell is overlapped by another value or another sum formula. <code>numbers[i]</code> could be on the format:
	<ul>
		<li><code>"ColRow"</code> that represents a single cell.
		<ul>
			<li>For example, <code>"F7"</code> represents the cell <code>mat[7]['F']</code>.</li>
		</ul>
		</li>
		<li><code>"ColRow1:ColRow2"</code> that represents a range of cells. The range will always be a rectangle where <code>"ColRow1"</code> represent the position of the top-left cell, and <code>"ColRow2"</code> represents the position of the bottom-right cell.
		<ul>
			<li>For example, <code>"B3:F7"</code> represents the cells <code>mat[i][j]</code> for <code>3 &lt;= i &lt;= 7</code> and <code>'B' &lt;= j &lt;= 'F'</code>.</li>
		</ul>
		</li>
	</ul>
	</li>
</ul>

<p><strong>Note:</strong> You could assume that there will not be any circular sum reference.</p>

<ul>
	<li>For example, <code>mat[1]['A'] == sum(1, "B")</code> and <code>mat[1]['B'] == sum(1, "A")</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["Excel", "set", "sum", "set", "get"]
[[3, "C"], [1, "A", 2], [3, "C", ["A1", "A1:B2"]], [2, "B", 2], [3, "C"]]
<strong>Output</strong>
[null, null, 4, null, 6]

<strong>Explanation</strong>
Excel excel = new Excel(3, "C");
 // construct a 3*3 2D array with all zero.
 //   A B C
 // 1 0 0 0
 // 2 0 0 0
 // 3 0 0 0
excel.set(1, "A", 2);
 // set mat[1]["A"] to be 2.
 //   A B C
 // 1 2 0 0
 // 2 0 0 0
 // 3 0 0 0
excel.sum(3, "C", ["A1", "A1:B2"]); // return 4
 // set mat[3]["C"] to be the sum of value at mat[1]["A"] and the values sum of the rectangle range whose top-left cell is mat[1]["A"] and bottom-right cell is mat[2]["B"].
 //   A B C
 // 1 2 0 0
 // 2 0 0 0
 // 3 0 0 4
excel.set(2, "B", 2);
 // set mat[2]["B"] to be 2. Note mat[3]["C"] should also be changed.
 //   A B C
 // 1 2 0 0
 // 2 0 2 0
 // 3 0 0 6
excel.get(3, "C"); // return 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= height &lt;= 26</code></li>
	<li><code>'A' &lt;= width &lt;= 'Z'</code></li>
	<li><code>1 &lt;= row &lt;= height</code></li>
	<li><code>'A' &lt;= column &lt;= width</code></li>
	<li><code>-100 &lt;= val &lt;= 100</code></li>
	<li><code>1 &lt;= numbers.length &lt;= 5</code></li>
	<li><code>numbers[i]</code> has the format <code>"ColRow"</code> or <code>"ColRow1:ColRow2"</code>.</li>
	<li>At most <code>100</code> calls will be made to <code>set</code>, <code>get</code>, and <code>sum</code>.</li>
</ul>
</div>
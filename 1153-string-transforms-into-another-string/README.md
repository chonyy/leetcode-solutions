<h2><a href="https://leetcode.com/problems/string-transforms-into-another-string/">1153. String Transforms Into Another String</a></h2><h3>Hard</h3><hr><div><p>Given two strings <code>str1</code> and <code>str2</code> of the same length, determine whether you can transform <code>str1</code> into <code>str2</code> by doing <strong>zero or more</strong> <em>conversions</em>.</p>

<p>In one conversion you can convert <strong>all</strong> occurrences of one character in <code>str1</code> to <strong>any</strong> other lowercase English character.</p>

<p>Return <code>true</code> if and only if you can transform <code>str1</code> into <code>str2</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> str1 = "aabcc", str2 = "ccdee"
<strong>Output:</strong> true
<strong>Explanation: </strong>Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> str1 = "leetcode", str2 = "codeleet"
<strong>Output:</strong> false
<strong>Explanation: </strong>There is no way to transform str1 to str2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= str1.length == str2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>str1</code> and <code>str2</code> contain only lowercase English letters.</li>
</ul>
</div>
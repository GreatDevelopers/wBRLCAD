<?php
$PHI = $_POST['pressure-angle'];
$PC = $_POST['circular-pitch'];
$teeth = $_POST['teeth'];

$command = "python gear.py " . $PHI . " " . $PC . " " . $teeth;

exec($command);
exec('inkscape -z -f file.svg --export-ps=file.ps');
exec('pstoedit -f dxf file.ps  file.dxf');
exec('zip dxffile.zip file.dxf');
echo " work complete ";
?>
<html><head><title>Process complete</title></head>
<body>
<table><tr>
<td><a href = "file.svg" > SVG Format File </a></td></tr>
<tr><td><a href = "dxffile.zip" > DXF Format File </a></td></tr></table></body></html>

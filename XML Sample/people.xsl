<?xml version="1.0"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<!-- 
	/ = root
	.. = parent node
	. = current node
	// = child node 
	-->
	<xsl:template match="/"> 
		<html>
		<head>
			<title>Mark Long</title>
		</head>
		<body>
			<table border="2">
				<tr>
				<xsl:apply-templates/>
				</tr>
			</table>
		</body>
		</html>
	</xsl:template>
	
	<xsl:template match="husband">
		<td><xsl:value-of select="name"/></td>
			<xsl:if test="age=42">
				one of the following people are 42 years old
			</xsl:if>
	</xsl:template>
</xsl:stylesheet>
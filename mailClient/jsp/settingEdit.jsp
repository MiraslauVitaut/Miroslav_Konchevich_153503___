<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<html>
<head>
<title>Настройки аккаунта</title>

<%@ include file='header.jsp' %>

</head>

<body style="text-align:center" >
<h1 align="center">Настройки акктаунта</h1>
<hr />

<p style="color: red;">${errorString}</p>

<form method="POST" action="${pageContext.request.contextPath}/settingEdit">

<div class="container">

<table class="table table-sm table-success table-hover table-bordered border-primary">
  <tr>
    <td>smtp.host:</td>
    <td><input type="text" name="SMTPHost" value="${setting.SMTPHost}" size="50" required /></td>
  </tr>
  <tr>
    <td>smtp.port:</td>
    <td><input type="text" name="SMTPPort" value="${setting.SMTPPort}" size="50" required /></td>
  </tr>
  <tr>
    <td>smtp.host:</td>
    <td><input type="text" name="POP3Host" value="${setting.POP3Host}" size="50" required /></td>
  </tr>
  <tr>
    <td>smtp.port:</td>
    <td><input type="text" name="POP3Port" value="${setting.POP3Port}" size="50" required /></td>
  </tr>
  <tr>
    <td>username:</td>
    <td><input type="text" name="username" value="${setting.username}" size="50" maxlength="50" required /></td>
  </tr>
  <tr>
    <td>password:</td>
    <td><input type="password" name="password" value="${setting.password}" size="50" maxlength="50" required /></td></td>
  </tr>
  <tr>
    <td colspan="2">
      <c:if test="${errorString == null}">
      <input type="submit" class="btn btn-danger" value="Записать" />
      </c:if>
      <a href="${pageContext.request.contextPath}/index.jsp">Назад</a>
    </td>
  </tr>
</table>

</div>

</form>

</body>

</html>
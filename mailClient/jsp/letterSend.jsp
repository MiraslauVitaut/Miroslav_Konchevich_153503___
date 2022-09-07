<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<html>
<head>
<title>Оправка письма</title>

<%@ include file='header.jsp' %>

</head>

<body style="text-align:center" >
<h1 align="center">Форма отправки письма</h1>
<hr />

<p style="color: red;">${errorString}</p>

<form method="POST" action="${pageContext.request.contextPath}/letterSend">

<div class="container">

<table class="table table-sm table-success table-hover table-bordered border-primary">
  <tr>
    <td>От кого:</td>
    <td><input type="text" name="username" value="${username}" size="50" readonly="readonly" required /></td>
  </tr>
  <tr>
    <td>Кому:</td>
    <td><input type="text" name="recipient" value="${recipient}" size="50" required /></td>
  </tr>
  <tr>
    <td>Тема:</td>
    <td><input type="text" name="subject" value="${subject}" size="50" maxlength="50" required /></td>
  </tr>
  <tr>
    <td>Сообщение:</td>
    <td><textarea width="99%" height="100%" name="body" style="width:99%;height:99%;" required>${body}</textarea></td>
  </tr>
  <tr>
    <td colspan="2">
      <c:if test="${errorString == null}">
      <input type="submit" class="btn btn-danger" value="Отправить" />
      </c:if>
      <a href="${pageContext.request.contextPath}/index.jsp">Назад</a>
    </td>
  </tr>
</table>

</div>

</form>

</body>

</html>
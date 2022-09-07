<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<html>
<head>
<title>Список полученных писем</title>

<%@ include file='header.jsp' %>

</head>

<body style="text-align:center" >
<h1 align="center">Список полученных писем</h1>
<hr />

<p style="color: red;">${errorString}</p>

<div class="container">
<div class="input-group input-group-sm justify-content-end">
  <a href="${pageContext.request.contextPath}/index.jsp">Назад</a>
</div>
</div>

<div class="container">
<table class="table table-sm table-success table-hover table-bordered border-primary">
  <thead class="table-dark">
    <tr><th>№ п/п</th><th>От кого</th><th>Тема</th><th>Сообщение</th><th>Дата посылки</th></tr>
  </thead>
  <tbody>
  <c:forEach items="${listMessages}" var="item" >
    <tr>
      <td>${item.msgId}</td>
      <td>${item.from}</td>
      <td>${item.subject}</td>
      <td>${item.content}</td>
      <td>${item.dateSent}</td>
    </tr>
  </c:forEach>
  </tbody>
</table>
</div>

</body>

</html>
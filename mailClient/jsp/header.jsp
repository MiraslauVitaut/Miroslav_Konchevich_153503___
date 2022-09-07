<%@ page pageEncoding="UTF-8"%>
<head>
  <style>
    ul.nav{ margin-left: 0px; padding-left: 0px; list-style: none; }
    .nav li { float: left; }
    ul.nav a { display: block; width: 10em; padding:10px; margin: 0 5px; background-color: #f4f4f4; border: 1px dashed #333; text-decoration: none; 
               color: #333; text-align: center; }
    ul.nav a:hover{ background-color: #333; color: #f4f4f4; }
  </style>
</head>

<link href="${pageContext.request.contextPath}/resources/bootstrap-5.0.1/css/bootstrap.min.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="${pageContext.request.contextPath}/resources/bootstrap-5.0.1/js/bootstrap.bundle.min.js"></script>

<script type="text/javascript" src="${pageContext.request.contextPath}/resources/js/header.js" charset="UTF-8"></script>

<ul class="nav">
  <li><a href="${pageContext.request.contextPath}/index.jsp">Главная</a></li>
  <li><a href="${pageContext.request.contextPath}/letterSend">Отправить</a></li>
  <li><a href="${pageContext.request.contextPath}/letterGet">Получить</a></li>
  <li><a href="${pageContext.request.contextPath}/settingEdit">Настройки</a></li>
</ul>

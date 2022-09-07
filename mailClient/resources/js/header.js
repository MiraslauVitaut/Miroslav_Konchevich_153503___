/**
 * добавить рандом к текущему урл
 *
 * @param url -
 *            урл
 */
function addRandom(url) {
    var rand = "random=" + Math.floor(Math.random() * 100000);
    var sep = getUrlSeparator(url);
    if (url)
        return url + sep + rand;
    else
        return rand;
}

/**
 * получить текущий разделитель & или ?
 *
 * @param url
 */
function getUrlSeparator(url) {
    if (typeof (url) == "string") {
        // alert(url);
        url = trimAll(url);
        if (url.length == 0)
            return "";
        var amp = url.lastIndexOf("&");
        var quest = url.lastIndexOf("?");
        if (quest == url.length - 1 || amp == url.length - 1)
            return "";
        if (quest < amp)
            return "&";
        if (amp < 0 && quest > 0)
            return "&";
        if (quest < 0 && amp < 0)
            return "?";
    }
    return "";
}

//****************************************************************************
//Аналог ф-ции trim() в Java( но!!!! удаление пробелов из любой позиции в строке ).
function trimAll(word){
    var letter = "";
    var i;
    var phrase = "";
    var tmp = "";
    if(word) tmp = word;
    for(i = 0; i < tmp.length; i++){
        if(tmp.charAt(i) != " "){
            letter = tmp.charAt(i);
            phrase = phrase + letter;
        }
    }

    return phrase;
}

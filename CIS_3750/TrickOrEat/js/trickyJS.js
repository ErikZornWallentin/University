$(document).ready(function() {
    $.sticky('The page has loaded!');
    var callnotification = function(){
        $.sticky('<b>You have a new message!</b>');
    }
    setInterval(callnotification,4000);
});
 
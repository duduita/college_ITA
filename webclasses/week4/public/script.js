$(document).ready(function(){
    $('.showData > button').click(function(){
        $.get("http://localhost:8081/list_users", function(data){
            $('.showData > p').html(data);
        });
    });
});
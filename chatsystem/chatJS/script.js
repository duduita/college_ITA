$(document).ready(function() {
    var socket = io.connect();

    $("form#chat").submit(function(e) {
        e.preventDefault();
        socket.emit("enviar mensagem", $(this).find("#texto_mensagem").val(), function() {
            $("form#chat #texto_mensagem").val("");
        });
        socket.on("atualizar mensagens", function(mensagem) {
            var mensagem_formatada = $("<p />").text(mensagem);
            $("#historico_mensagens").append(mensagem_formatada);
        });
    });
});
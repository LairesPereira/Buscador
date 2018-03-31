$(document).ready(function(){
    //~Laires~ Verifica se o user está logado assim que a pagina carrega
    if(window.localStorage.getItem('logado') === 'true'){
        $('.more-options').append
        ('<button onclick="anunciarProd()" class="dropdown-item anunciar">Anunciar</button>')//cria o botao de anunciar
    } 

    function anunciarProd(){
            console.log('okay okay')
    }
})





$(document).ready(function(){
    //~Laires~ Verifica se o user está logado assim que a pagina carrega
    if(window.localStorage.getItem('logado') === 'true'){
        $('.anunciar').css('display', 'initial')
        //mostra o botao de anunciar
    }    
})

function anunciarProd(){
    console.log('okay okay')
}
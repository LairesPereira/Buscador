$(document).ready(function () {
    //~Laires~ Verifica se o user está logado assim que a pagina carrega
    if (sessionStorage.getItem('logado') === 'true') {
        $('.anunciar').css('display', 'initial')

        //mostra o botao de anunciar
    }
})

function logar(){
    if($('.login-password').val() == sessionStorage.getItem('senha') && 
       $('.login-email').val() == sessionStorage.getItem('email')
    ) {
        sessionStorage.setItem('logado', 'true')
        alert('Logado com sucesso')
        $('.anunciar').css('display', 'initial')
    } else {
        alert('erro no login')
    }
}

var produtosDaPagina = []

function anunciarProd() {

    if ($('#nome-anuncio').val() === '' ||
        $('#valor-anuncio').val() === '' ||
        $('#descricao-anuncio').val() === '' ||
        $('#link-anuncio').val() === '' ||
        $('#tipo-anuncio').val()
    ) {
        alert('Preencha todos os campos.')
    }



    var novoProduto = new Object()
    novoProduto.nome = $('#nome-anuncio').val()
    novoProduto.valor = $('#valor-anuncio').val()
    if ($('#descricao-anuncio').val().length > 80) {
        novoProduto.descricao = $('#descricao-anuncio').val().substring(0, 80) + '...'
    } else {
        novoProduto.descricao = $('#descricao-anuncio').val()
    }
    novoProduto.link = $('#link-anuncio').val()
    produtosDaPagina.unshift(novoProduto)
    console.log(produtosDaPagina[0])

    $('.row-products').prepend('<div class="col-md-4">' + '<div class="card" style="width: 18rem;">' + '<img class="card-img-top" src="https://img.ibxk.com.br/2012/12/materias/33810716244.jpg" alt="Card image cap">' +
        '<div class="card-body">' +
        '<h4 class="card-title titulo">' + novoProduto.nome + '</h4>' +
        '<p type="textarea" class="card-text descricao">' + novoProduto.descricao + '</p>' +
        '<h5 class="preco">' + novoProduto.valor + '</h5>' +
        '<a target="_blank" href="' + novoProduto.link + '" class="btn btn-primary">Comprar</a>' +
        '</div>' +
        '</div>' +
        '</div>')

}
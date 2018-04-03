$(document).ready(function () {
    //~Laires~ Verifica se o user está logado assim que a pagina carrega
    if (window.localStorage.getItem('logado') === 'true') {
        $('.anunciar').css('display', 'initial')

        //mostra o botao de anunciar
    }
})

var produtosDaPagina = []
var rowsNumber = 1

function anunciarProd() {

    if ($('#nome-anuncio').val() === '' ||
        $('#valor-anuncio').val() === '' ||
        $('#descricao-anuncio').val() === '' ||
        $('#link-anuncio').val() === '' ||
        $('#tipo-anuncio').val()
    ) { return }

        var novoProduto = new Object()
    novoProduto.nome = $('#nome-anuncio').val()
    novoProduto.valor = $('#valor-anuncio').val()
    novoProduto.descricao = $('#descricao-anuncio').val()
    novoProduto.link = $('#link-anuncio').val()
    novoProduto.tipo = $('#tipo-anuncio').val()
    produtosDaPagina.unshift(novoProduto)
    console.log(produtosDaPagina[0])
    exibeProd(produtosDaPagina[0])
}

function exibeProd(produtoObj) {
    console.log($('.products-row-' + rowsNumber).children().length + 1)
    if ($('.products-row-' + rowsNumber).children().length === 3) { //verifica quantos "filhos" a linha tem, se = 3, cria nova linha
        rowsNumber++
        $('products-grid').append("<div class='row products-row-" + rowsNumber + "'></div>>")
        $('.products-row-' + rowsNumber).append('<div class="col-md-4">' + '<div class="card" style="width: 18rem;">' + '<img class="card-img-top" src="https://img.ibxk.com.br/2012/12/materias/33810716244.jpg" alt="Card image cap">' +
            '<div class="card-body">' +
            '<h4 class="card-title titulo">' + produtoObj.nome + '</h4>' +
            '<p class="card-text descricao">' + produtoObj.descricao + '</p>' +
            '<h5 class="preco">' + produtoObj.valor + '</h5>' +
            '<a target="_blank" href="' + link + '" class="btn btn-primary">Comprar</a>' +
            '</div>' +
            '</div>' +
            '</div>')
    }
}
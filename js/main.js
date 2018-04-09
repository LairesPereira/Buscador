$(document).ready(function () {
    //~Laires~ Verifica se o user está logado assim que a pagina carrega
    if (sessionStorage.getItem('logado') === 'true') {
        $('.anunciar').css('display', 'initial')
        $('#login').css('display', 'none');
        $('.sair').css('display', 'initial')
        $('#cadastro2').css('display', 'none'); 
               //mostra o botao de anunciar
    }
})

function logar(){
    if($('.login-password').val() == sessionStorage.getItem('senha') && 
       $('.login-email').val() == sessionStorage.getItem('email')
    ) {
        sessionStorage.setItem('logado', 'true');
        alert('Logado com sucesso');
        $('.anunciar').css('display', 'initial');
        $('#cadastro2').css('display', 'none'); 
        $('#login').css('display', 'none');      
    } else {
        alert('erro no login');
    }
    $('#exampleModal').modal('hide');
}

var produtosDaPagina = []

var imagemupload = null;

$(document).on('change', '.btn-file :file', function() {
    var input = $(this),
        label = input.val().replace(/\\/g, '/').replace(/.*\//, '');
    input.trigger('fileselect', [label]);
    });

    $('.btn-file :file').on('fileselect', function(event, label) {
        
        var input = $(this).parents('.input-group').find(':text'),
            log = label;
        
        if( input.length ) {
            input.val(log);
        } else {
            if( log );
        }
    
    });
    function readURL(input) {
        if (input.files && input.files[0]) {
            var reader = new FileReader();
            
            reader.onload = function (e) {
                $('#img-upload').attr('src', e.target.result);
                imagemupload = e.target.result;
            }
            
            reader.readAsDataURL(input.files[0]);
        }
    }

    $("#imgInp").change(function(){
        readURL(this);
    });

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
$('.row-products').prepend('<div class="col-md-4">' + '<div class="card" style="width: 18rem;">' + '<img class="card-img-top" src="' + imagemupload + '" alt="Card image cap">' +
    '<div class="card-body">' +
    '<h4 class="card-title titulo">' + novoProduto.nome + '</h4>' +
    '<p type="textarea" class="card-text descricao">' + novoProduto.descricao + '</p>' +
    '<h5 class="preco">' + 'Preço: R$' + novoProduto.valor + '</h5>' +
    '<a target="_blank" href="' + novoProduto.link + '" class="btn btn-primary">Comprar</a>' +
    '</div>' +
    '</div>' +
    '</div>')
}
function sairlogin(){
    sessionStorage.removeItem('logado')
    location.reload();

}
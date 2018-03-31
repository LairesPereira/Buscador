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

<<<<<<< HEAD



=======
function verificaLogin(){
    
}
$(document).ready(function() {
	$('#meuform').validate({
		rules: {
			Email: {
				required: true,
				email: true
			},
			password: {
				required: true,
				minlength: 4
			},
			confirm_password: {
				required: true,
				equalTo: "#password"
			},
			Nome: {
				required: true,
				minlength: 5
			},
			CPF: {
				
			},
			Nascimento: {
				
			},
			Numero: {
				
			},
			RG: {
				
			},
			Rua: {
				
			},
			Bairro: {
				
			},
			CEP: {
				
			},
			Estado: {
				
			},
			Cidade: {
				
			},
			Contrato: {
				required: true
			}
		},
		messages: {
			
		}
	});
});
>>>>>>> d3a12f70af5f5b98e12ecdc7bb6a7750f2a2d605

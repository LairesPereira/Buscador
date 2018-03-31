$(document).ready(function(){
    console.log('carregou')
    $('.login-btn').click(function() { verificaLogin() })
})

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
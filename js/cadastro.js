$('#meuform').submit(function(event) {
	$('#meuform').validate ({
		rules: {
			email: {
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
				required: true,
				minlength: 11,
				maxlength: 11
			},
			Nascimento: {
				required: true,
				minlength: 10,
				maxlength: 10
			},
			Numero: {
				required: true,
				minlength: 11,
				maxlength: 11
			},
			RG: {
				required: true,
				minlength: 9,
				maxlength: 9
			},
			Rua: {
				required: true,
				minlength: 5,
				maxlength: 50
			},
			Bairro: {
				required: true,
				minlength: 5,
				maxlength: 50
			},
			CEP: {
				required: true,
				minlength: 8,
				maxlength: 8
			},
			Contrato: {
				required: true
			}
		},
		messages: {
			
		}
	});
	event.preventDefault();
});
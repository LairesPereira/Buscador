function salvaCadastro(){
	var email = $('.email-cadastro').val();
	var password = $('.senha-cadastro').val();
	sessionStorage.setItem('email', email);
	sessionStorage.setItem('senha', password);
	console.log(email, password);
	window.location = "index.html";
}




/*-----------Variaveis para servir como expressões regulares----------*/
//estas expressões regulares irão funcionar como base para a validação dos campos do cadastro;
//São objetos do tipo RegExp;
var cpf = /^[0-9]{3,3}\.[0-9]{3,3}\.[0-9]{3,3}\-[0-9]{2,2}$/;
//A expressão regular para o CPF irá validar apenas os campos que seguirem o padrão:"999.999.999-99";
var data = /^[0-9]{2,2}\/[0-9.]{2,2}\/[0-9.]{4,4}$/;
//A expressão regular para data irá validar somente os campos com o seguinte padrão:"99/99/9999";
var email = /^[a-zA-Z0-9.!#$%&'*+/=?^_`~-]+@[a-z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$/;
//A expressão regular para email é um pouco mais complicada;
//ela funciona em dois escopos, tudo que tem antes e tudo que tem depois do '@';
//é necessário ter pelo menos 1 caracetere do lado esquero do '@'
//já do lado direito, ele vai validar dois tipos de expressão; do tipo "exemplo.com" e "exemplo.com.br". sendo opcional a string apartir do segundo ponto;
var phone = /^\([0-9.]{2,2}\) [0-9.]{5,5}\-[0-9.]{4,4}$/;
//A expressão regular para Numero de telefone valida apenas os campos no formato: "(99) 99999-9999";
var nome = /^[a-zA-Z ]{2,45}$/;
//A expressão regular para nome valida nomes de 2 até 45 caracteres (sujeito a mudança);
//Contendo ela Letras maiúsculas e minúsculas apenas;
var password = /^[a-zA-Z0-9.#$%&*_]{6,30}$/;
//A expressão regular para senha valida senhas de 6 até 30 caracteres (sujeito a mudança);
//Contendo ela letras, numeros e alguns caracteres especiais; 
//var rua = /^[a-zA-Z0-9~^´`]{4,60}$/;
//A expressão regular para rua valida strings de 4 até 60 caracteres (sujeito a mudança);
//Contendo ela letras ou números;
var bairro = /^[a-zA-Z0-9]{4,30}$/;
//A expressão regular para o bairro valida strings de 4 até 30 caracteres (sujeito a mudança);
//Contendo ela letras ou números;
var cep = /^[0-9]{5,5}\-[0-9]{3,3}$/;
//A expressão regular para o CEP valida apenas os campos no formato: "99999-999";

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
		        }
		        
		        reader.readAsDataURL(input.files[0]);
		    }
		}

		$("#imgInp").change(function(){
		    readURL(this);
		});
//Função da pre visualização da imagem

/*----------Funções de atualização dinâmica dos campos----------*/

//Esta função vai cuidar da atualização dinâmica do campo de CPF, para que o usuário digite apenas os números;
// 999.999.999-99
//    4   8   12  (índices de atualização);
function corrigirCpf(){
	var tamanho = document.getElementById("CPF").value.length
	if((tamanho==3)||(tamanho==7)){
		document.getElementById("CPF").value += ".";
	}
	if(tamanho==11) document.getElementById("CPF").value += "-";
}
//Esta função vai cuidar da atualização dinâmica do campo de Data de Nascimento, para que o usuário digite apenas os números;
// 99/99/9999
//   3  6     (índices de atualização);
function corrigirData(){
	var tamanho = document.getElementById("data").value.length;
	if((tamanho==2)||(tamanho==5)){
		document.getElementById("data").value += "/";
	}
}
//Esta função vai cuidar da atualização dinâmica do campo de Número de telefone, para que o usuário digite apenas os números;
// (99) 99999-9999
// 1  4      11    (índices de atualização);
function corrigirTelefone(){
	var texto = document.getElementById("telefone").value;
	var tamanho = texto.length;
	if(tamanho==2){
		document.getElementById("telefone").value = "("+texto+") ";
	}
	if(tamanho==10){
		document.getElementById("telefone").value += "-";
	}
}
//Esta função vai cuidar da atualização dinâmica do campo de CEP, para que o usuário digite apenas os números;
// 99999-999
//      6    (índices de atualização);
function corrigirCep(){
	var tamanho = document.getElementById("CEP").value.length;
	if(tamanho==5){
		document.getElementById("CEP").value += "-";
	}
}
                                  /*-------------INCOMPLETA----------*/
//Esta função irá testar e validar todos os campos do cadastro;
//Ela irá utilizar das Expressões regulares para testar os campos digitados pelo usuário;
//Se algum dos campos estiver fora do padrão, ele será destacado de vermelho para que o usuário possa concertar;
var cadastroform = new Array();
function validarCampos(){
	var pessoa = {email: null, senha: null, confirmarsenha: null, nome: null, cpf: null, datadenascimento: null, telefone: null, sexo: null, rg: null, rua: null, bairro: null, cep: null, estado: null, cidade: null}
	var validado = true; //esta variável dará a palavra final sobre a validação de todos os campos;
	var userPassword = document.getElementById("password").value;
	var confirmUserPassword = document.getElementById("confirm_password").value;
	//testa a validação do email;
	if(!email.test(document.getElementById("email").value)){
		$("#email").css("border-color","red");
		validado = false;
	}
	else {
		pessoa.email = document.getElementById("email").value;
	}
	//testa a validação da senha;
	if(!password.test(userPassword)){
		$("#password").css("border-color","red");
		validado = false;
	}
	else {
		pessoa.senha = document.getElementById("password").value;
	}
	//faz a comparação da senha e da confirmação de senha para ver se os dois valores batem;
	if(userPassword!=confirmUserPassword){
		$("#confirm_password").css("border-color","red");
		validado = false;
	}
	else {
		pessoa.confirmarsenha = document.getElementById("confirm_password").value;
	}
	//testa a validação do nome;
	if(!nome.test(document.getElementById("Nome").value)){
		$("#Nome").css("border-color","red");
		validado = false;
	}
	else {
		pessoa.nome = document.getElementById("Nome").value;
	}
	//testa a validação do CPF;
	if(!cpf.test(document.getElementById("CPF").value)){
		$("#CPF").css("border-color","red");
		validado = false;
	}
	else {
		pessoa.cpf = document.getElementById("CPF").value;
	}
	//testa a validação da Data de Nascimento;
	if(!data.test( document.getElementById("data").value)){
		$("#data").css("border-color","red");
		validado = false;
	}
	else {
		pessoa.datadenascimento = document.getElementById("data").value;
	}
	//testa a validação do Número de telefone;
	if(!phone.test(document.getElementById("telefone").value)){
		$("#telefone").css("border-color","red");
		validado = false;
	}
	else {
		pessoa.telefone = document.getElementById("telefone").value;
	}
	//testa a validação da Rua;
	if((document.getElementById("Rua").value) == ''){
		$("#Rua").css("border-color","red");
		validado = false;
	}
	else {
		pessoa.rua = document.getElementById("Rua").value;
	}
	//testa a validação do Bairro;
	if((document.getElementById("Bairro").value) == ''){
		$("#Bairro").css("border-color","red");
		validado = false;
	}
	else {
		pessoa.bairro = document.getElementById("Bairro").value;
	}
	//testa a validação do CEP;
	if(!cep.test(document.getElementById("CEP").value)){
		$("#CEP").css("border-color","red");
		validado = false;
	}
	else {
		pessoa.cep = document.getElementById("CEP").value;
	}
	pessoa.rg = document.getElementById("RG").value;
	var a = document.getElementById("sexo");
	var itemSelecionadoa = a.options[a.selectedIndex].value;
	pessoa.sexo = itemSelecionadoa;
	var b = document.getElementById("estado");
	var itemSelecionadob = b.options[b.selectedIndex].value;
	pessoa.estado = itemSelecionadob;
	var c = document.getElementById("cidade");
	var itemSelecionadoc = c.options[c.selectedIndex].value;
	pessoa.cidade = itemSelecionadoc;
	//Testa se todos os campos foram validados com sucesso;
	if(validado){
		cadastroform.push(pessoa);
		alert("usuário cadastrado com sucesso!");
	}
}

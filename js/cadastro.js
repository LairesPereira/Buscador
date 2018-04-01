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
var phone = /\([0-9.]{2,2}\) [0-9.]{5,5}\-[0-9.]{4,4}/;
//A expressão regular para Numero de telefone valida apenas os campos no formato: "(99) 99999-9999";
var nome = /^[a-zA-Z ]{2,45}$/;
//A expressão regular para nome valida nomes de 2 até 45 caracteres (sujeito a mudança);
//Contendo ela Letras maiúsculas e minúsculas apenas;
var password = /^[a-zA-Z0-9.#$%&*_]{6,30}$/;
//A expressão regular para senha valida senhas de 6 até 30 caracteres (sujeito a mudança);
//Contendo ela letas, numeros e alguns caracteres especiais; 
var rua = /^[a-zA-Z0-9 ]{4,60}$/;
//A expressão regular para rua valida strings de 4 até 60 caracteres (sujeito a mudança);
//Contendo ela letras ou números;
var bairro = /^[a-zA-Z0-9]{4,30}$/;
//A expressão regular para o bairro valida strings de 4 até 30 caracteres (sujeito a mudança);
//Contendo ela letras ou números;
var cep = /^[0-9]{5,5}\-[0-9]{3,3}$/;
//A expressão regular para o CEP valida apenas os campos no formato: "99999-999";

function PreviewImage() { 
        var oFReader = new FileReader(); 
        oFReader.readAsDataURL($("#Image").files[0]);

        oFReader.onload = function (oFREvent) { 
            $("#uploadPreview").src = oFREvent.target.result; 
        }; 
    };
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
function validarCampos(){
	var validado = true; //esta variável dará a palavra final sobre a validação de todos os campos;
	var userPassword = document.getElementById("password").value;
	var confirmUserPassword = document.getElementById("confirm_password").value;
	//testa a validação do email;
	if(!email.test(document.getElementById("email").value)){
		$("#email").css("border-color","red");
		validado = false;
	}
	//testa a validação da senha;
	if(!password.test(userPassword)){
		$("#password").css("border-color","red");
		validado = false;
	}
	//faz a comparação da senha e da confirmação de senha para ver se os dois valores batem;
	if(userPassword!=confirmUserPassword){
		$("#confirm_password").css("border-color","red");
		validado = false;
	}
	//testa a validação do nome;
	if(!nome.test(document.getElementById("Nome").value)){
		$("#Nome").css("border-color","red");
		validado = false;
	}
	//testa a validação do CPF;
	if(!cpf.test(document.getElementById("CPF").value)){
		$("#CPF").css("border-color","red");
		validado = false;
	}
	//testa a validação da Data de Nascimento;
	if(!data.test( document.getElementById("data").value)){
		$("#data").css("border-color","red");
		validado = false;
	}
	//testa a validação do Número de telefone;
	if(!phone.test(document.getElementById("telefone").value)){
		$("#telefone").css("border-color","red");
		validado = false;
	}
	//testa a validação da Rua;
	if(!rua.test(document.getElementById("Rua").value)){
		$("#Rua").css("border-color","red");
		validado = false;
	}
	//testa a validação do Bairro;
	if(!bairro.test(document.getElementById("Bairro").value)){
		$("#Bairro").css("border-color","red");
		validado = false;
	}
	//testa a validação do CEP;
	if(!cep.test(document.getElementById("CEP").value)){
		$("#CEP").css("border-color","red");
		validado = false;
	}
	//Testa se todos os campos foram validados com sucesso;
	if(validado){
		alert("usuário cadastrado com sucesso!");
	}
}


//Falta ainda a validação do RG e a implementação desta função no botão do formulário;
//Esta função está sendo ativada por meio de gambiarra no botão localizado no canto inferior esquedo da pagina, para que se possa testar tudo;
//Um grande abraço e um beijo pra vcs, meus lindos <3;

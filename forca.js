let palavras = ['fazendeiro','nutrologo','apicultor','agronomo','bartender','cerimonialista','desembargador','endocrinologista','nanotecnologo','roteirizador',
'albatroz','hipopotamo','escaravelho','golfinho','percevejo','papagaio','texugo','rouxinol','bacalhau','lhama',
'ampulheta','botijao','candelabro','desfibrilador','almofada','vuvuzela','webcam','tijolo','fantoche','parede',
'abacate','bergamota','acerola','groselha','carambola','mexerica','nectarina','pistache','melancia','abacaxi'
];

let indice = Math.floor(Math.random() * (39));
let palavraAleatoria = palavras[indice];

let dica = document.querySelector('#dica');

let palavraPreencher = [];
let j=0;

for (let i of palavraAleatoria){
    palavraPreencher[j] = '_';
    j++;
}

console.log(palavraAleatoria);
console.log(palavraPreencher);

if(indice <10){
    dica.innerText += ' profissao\n';
}
else if(indice <20){
    dica.innerText += ' animal\n';
}
else if(indice <30){
    dica.innerText += ' objeto\n';
}
else{
    dica.innerText += ' fruta\n';
}

let node = document.createElement('div');                 
let textnode = document.createTextNode(palavraPreencher);       
node.appendChild(textnode);                            
document.querySelector('#dica').appendChild(node);

function criaPalavra(str,pos,letra,preenchida){
    let newStr = [];
    for(let i=0;i<str.length;i++){
        if(i == pos){
            newStr[i] = letra;
        }
        else if(preenchida[i] === '_'){
            newStr[i] = '_';
        }
        else{
            newStr[i] = preenchida[i];
        }
    }

    console.log(newStr);
    return newStr;
}

let chances =5;
let qtdLetras = palavraAleatoria.length;
let ver =0;
let letrasUtilizadas = [];
let qtdLetrasUtilizadas = 0;


let letra = document.getElementById('letra');

let qtdChancesTexto = document.createElement('div');
let chancesTexto = document.createTextNode('');
qtdChancesTexto.appendChild(chancesTexto);
document.querySelector('#dica').appendChild(qtdChancesTexto);

letra.addEventListener('input',function(evt){
    let k =0;
    evt.preventDefault();
    console.log(this.value);

    for (let i of palavraAleatoria){

        if(this.value === i){
            palavraPreencher = criaPalavra(palavraAleatoria,k,this.value,palavraPreencher);
            qtdLetras--;
            ver = 1;    
        }
        k++;
        
    }
    if(ver === 0){
        chances--;
        chancesTexto.textContent = `VOCE TEM ${chances} CHANCES! `;
        chancesTexto.textContent += `\nESSA LETRA NAO ESTA NA PALAVRA,LETRAS JA UTILIZADAS:`;
        letrasUtilizadas[qtdLetrasUtilizadas] = this.value;
        qtdLetrasUtilizadas++;
        chancesTexto.textContent +=`\n ${letrasUtilizadas}`;

    }
    else{
        ver = 0;
    }
    textnode.textContent = palavraPreencher;

    if(qtdLetras === 0){
        chancesTexto.textContent = `VOCE VENCEU!!! PARABENS`;
    }
    if(chances === 0){
        chancesTexto.textContent = `VOCE PERDEU!!! a palavra era: ${palavraAleatoria}`;
    }

    setTimeout(()=>{
        letra.value = '';
    },300);
})

let recomecar = document.querySelector('#recomecar');

recomecar.addEventListener('click',function(evt){
    evt.preventDefault();
    document.location.reload(true);
})
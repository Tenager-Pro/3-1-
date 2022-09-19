window.onload=function(){
    
    for (var i=0; i<9;i++){
        document.getElementById('game').innerHTML+='<div class="block"></div>';
    
    }
    var hod = 0;
    document.getElementById('game').onclick=function(event){
        console.log(event);
        if(event.target.className=='block'){
            if(hod %2==0 && event.target.innerHTML==''){
                event.target.innerHTML='x';
                hod++;
            }
            if(hod %2==1 && event.target.innerHTML==''){
                event.target.innerHTML='0';
                hod++;
            }
           
           checkWinner();
        }
    }
    
    function checkWinner(){
        var allblock=document.getElementsByClassName('block');
        let x =3;
        sumX=[0,0,0];
        sumY=[0,0,0];
        sumD=[0,0,0];
        sum1X=[0,0,0];
        sum1Y=[0,0,0];
        sum1D=[0,0,0];
        let flag=false;
        let flag1=false;
        let mag=[2,7,6,9,5,1,4,3,8];
        for(let i=0;i<allblock.length;i++){
            if(allblock[i].innerHTML=='x'){
                for(let j=0;j<(x);j++){
                    if(x*(j)<i<(x*(j+1))){
                        sumX[j]+=mag[i];
                        console.log(sumX[j]);
                        if(sumX[j]==15) flag=true;
                    }
                }
                for (let z=0;z<(x);z++){
                    for(let j=0;j<(x);j++){
        
                        if(i==j*x+z){
                            sumY[j]+=mag[i];
                            if(sumY[j]==15) flag=true;
                        }
                    }
                }
                for(let j=0;j<(x);j++){
                    if(i==(j*x+(j*1))){
                        sumD +=mag[i];
                        if(sumD[j]==15) flag=true;
                    }
                }
                for(let j=x-1;j>=(0);j--){
                    if(i==(j*x+(j*1))){
                        sumD +=mag[i];
                        if(sumD[j]==15) flag=true;
                    }
                 
                } 

                if(flag){alert('Сrosses win!');}
                
            }
            if(allblock[i].innerHTML=='0'){
                for(let j=0;j<(x);j++){
                    if(x*(j)<i<(x*(j+1))){
                        sum1X[j]+=mag[i];
                        console.log(sumX[j]);
                        if(sum1X[j]==15) flag1=true;
                    }
                }
                for (let z=0;z<(x);z++){
                    for(let j=0;j<(x);j++){
        
                        if(i==j*x+z){
                            sum1Y[j]+=mag[i];
                            if(sum1Y[j]==15) flag1=true;
                        }
                    }
                }
                for(let j=0;j<(x);j++){
                    if(i==(j*x+(j*1))){
                        sum1D +=mag[i];
                        if(sum1D[j]==15) flag1=true;
                    }
                }
                for(let j=x-1;j>=(0);j--){
                    if(i==(j*x+(j*1))){
                        sum1D +=mag[i];
                        if(sum1D[j]==15) flag1=true;
                    }
                 
                } 
                if(flag1){alert('Нолики win!');}
            }
        }

    }

}


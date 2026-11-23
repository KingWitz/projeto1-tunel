#define DHTPIN 4          
#define DHTTYPE DHT22     


DHT dht(DHTPIN, DHTTYPE);


//Variáveis globais
int lotacao=0;
bool alerta=false;
float humidade;
float temperatura;


//Variaveis tempo
long TempoInicial=millis();
long tempoDetetar_alerta=2000; //intervalo de tempo entre cada leitura dos sensores




int DetetarAlerta(){                                        // Função de deteção de perigo responsável por detetar perigo e acionar o alerta
  int aux=0;
  if(millis()-TempoInical>=tempoDetetar_alerta=2000){
  TempoIncical=millis();
  humidade = dht.readHumidity();
  temperatura = dht.readTemperature();
  //fumo = ;
    if(isnan(humidade)){
      Serial.println("ERRO AO LER HUMIDADE!!!");
      aux=-1;
    }
    /*else if(!fumo()){
      Serial-println("ERRO AO LER FUMO!!!");
      aux= aux+(-1);
    }*/
    else if(isnan(temperatura)){
      Serial.println("ERRO AO LER TEMPERATURA!!!");
      aux=aux+(-1);
    }

    else if(temperatura>=25){
      Serial.println("PERIGO DETETADO!")
      alerta=true;
      aux= 1;
    }
    else{
      aux=0;
      alerta=false;
    }
  }
  return aux;
};


void setup() {
  // put your setup code here, to run once:

}

void loop() {


  //Sistema lotação
  //...

  //Sistema de reação a perigo
  if(DetetarAlerta()<0 &&)Serial.println("Chamar Manutencão");
  if(alerta){
      //funções de sinalização(display, semáforo, cancela. ventoinha)
    }
  else{
    //função 
  }




}

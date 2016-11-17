void draw(){
  OrbitOledClear();
  int songLength=0;
  int artistLength=0;
  for(int i = 0; i < inputLength; i++)
  {
    if(inputText[i] == '~')
    {
      songLength = i;
      artistLength = inputLength-(i+1);
    }
  }
  char song[songLength];
 
  char artist[artistLength];
  if(songLength){
    memcpy(song, inputText, songLength);
    memcpy(artist, inputText+songLength+1, artistLength); 
    OrbitOledMoveTo(0, 0);
    OrbitOledDrawString(song);
    OrbitOledMoveTo(0, 10);
    OrbitOledDrawString(artist);
  }
  
  int startPosX = 0;
  int startPosY = 21;
  if(toggle)
  {
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledLineTo(startPosX,startPosY+10);
    OrbitOledMoveTo(startPosX,startPosY+10);
    OrbitOledLineTo(startPosX+10,startPosY+5);
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledLineTo(startPosX+12,startPosY+6);
  }
  else
  {
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledDrawRect(startPosX+3, startPosY+10);
    OrbitOledMoveTo(startPosX+5,startPosY);
    OrbitOledDrawRect(startPosX+8, startPosY+10);
  }
  drawVolume();
  OrbitOledUpdate();
}

void drawVolume(){
  int bars = 0;
  if(0 <= previousVolume && previousVolume < 20){
    bars = 1;
  }else if(20 <= previousVolume && previousVolume < 40){
    bars = 2;
  }else if(40 <= previousVolume && previousVolume < 60){
    bars = 3;  
  }else if(60 <= previousVolume && previousVolume < 80){
    bars = 4;
  }else if(80 <= previousVolume && previousVolume <= 100){
    bars = 5;  
  }else{
    bars = 0;
  }

  int rectangleStartX = 20;
  int rectangleStartY = 25;
  
  for(int i = 0; i < bars; i++){
    OrbitOledMoveTo(rectangleStartX,rectangleStartY);
    OrbitOledDrawRect(rectangleStartX+1, rectangleStartY+5+i*2);
    OrbitOledMoveTo(rectangleStartX,rectangleStartY);
    rectangleStartX = rectangleStartX + 2;
    rectangleStartY = rectangleStartY - 2;
  }
}
  

public class CountOccur {
  String sentence,word;
  public CountOccur(String sentence,String word){
    this.sentence=sentence;
    this.word=word;
  }

  public int Count(){
    int numOfOccurences=0;
    int startIndex=0;
    int sentenceLength=this.sentence.length();

    while (startIndex<=sentenceLength){
    int index=this.sentence.indexOf(this.word,startIndex);
    if(index>0){
      numOfOccurences++;
      startIndex=index+1;
    }else{
      break;
      }
    }
    return numOfOccurences;
  }
}


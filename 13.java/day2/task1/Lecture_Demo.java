public class Lecture_Demo{

  public static void main(String[] args) {
    String cmdLine="192.168.1.1";
    IPCutter ip=new IPCutter(cmdLine);

    int[] ipList=ip.doIPSplit();
    for (int i = 0; i < ipList.length; i++) {
      System.out.println(ipList[i]);
    }
  }
  
}

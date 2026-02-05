public class IPCutter{
  String cmdLine;
  public IPCutter(String cmdLine) {
    this.cmdLine=cmdLine;
  }

  public int[] doIPSplit(){
    String[] splittedIP;
    splittedIP = this.cmdLine.split("\\.");

    int[] ipList=new int[splittedIP.length];

    for (int i = 0; i < splittedIP.length; i++) {
      ipList[i]=Integer.parseInt(splittedIP[i]);
    }
    return ipList;
  }
}

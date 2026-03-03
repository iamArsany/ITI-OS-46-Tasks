package lab1;

import java.util.List;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class ReadCSV {
  FileReader fileReader;
  BufferedReader bufferedReader;

  String FilePath;

  public ReadCSV(String filePath) throws IOException {
    this.FilePath = filePath;
  }

  public List<List<String>> ArrayListOfLines() throws IOException {
    String line;
    List<List<String>> CSVList = new ArrayList<List<String>>();
    fileReader = new FileReader(this.FilePath);
    bufferedReader = new BufferedReader(fileReader);
    while ((line = bufferedReader.readLine()) != null) {
      String[] splittedLine = line.split(",");
      CSVList.add(Arrays.asList(splittedLine));
    }

    this.bufferedReader.close();
    return CSVList;
  }

}

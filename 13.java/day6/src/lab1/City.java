package lab1;

import java.util.ArrayList;
import java.util.List;

public class City {

  public int id;
  public String name;
  public int population;
  public String countryCode;

  public City(List<String> cityString) {
    this.id = Integer.parseInt(cityString.get(0));
    this.name = cityString.get(1).trim();
    this.population = Integer.parseInt(cityString.get(2));
    this.countryCode = cityString.get(3).trim();
  }

  public static List<City> arrayToObject(List<List<String>> stringListcities) {
    List<City> objectListcities = new ArrayList<>();

    for (List<String> cityString : stringListcities) {
      City cityObj = new City(cityString);
      objectListcities.add(cityObj);
    }

    return objectListcities;
  }
}

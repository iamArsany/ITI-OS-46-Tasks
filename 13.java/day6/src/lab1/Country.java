package lab1;

import java.util.ArrayList;
import java.util.List;

/**
 * Country
 */
public class Country {
  public String name;
  public String code;
  public String continent;
  public double surfaceArea;
  public int population;
  public double gnp;
  public int capital;

  public Country(List<String> countryString) {
    this.code = countryString.get(0).trim();
    this.name = countryString.get(1).trim();
    this.continent = countryString.get(2).trim();
    this.population = Integer.parseInt(countryString.get(3));
    this.surfaceArea = Double.parseDouble(countryString.get(4));
    this.gnp = Double.parseDouble(countryString.get(5));
    this.capital = Integer.parseInt(countryString.get(6));
  }

  public static List<Country> arrayToObject(List<List<String>> stringListcountries) {
    List<Country> objectListcountries = new ArrayList<>();

    for (List<String> countryString : stringListcountries) {
      Country countryObj = new Country(countryString);
      objectListcountries.add(countryObj);
    }
    return objectListcountries;
  }
}

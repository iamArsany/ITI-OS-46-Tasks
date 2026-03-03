package lab1;

import java.util.List;

/**
 * Main
 */
public class Main {

  public static void main(String[] args) {
    try {
      ReadCSV Cities = new ReadCSV("/home/miles/Desktop/Programs/ITI/13.java/day6/Cities.csv");
      ReadCSV Countries = new ReadCSV("/home/miles/Desktop/Programs/ITI/13.java/day6/Countries.csv");
      List<City> CitiesObjList = City.arrayToObject(Cities.ArrayListOfLines());
      List<Country> CountriesObjList = Country.arrayToObject(Countries.ArrayListOfLines());

      Main.GreatestPopulation(CitiesObjList, CountriesObjList);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static void GreatestPopulation(List<City> cities, List<Country> countries) {
    // Main.getHighestPopulatedCityPerCountry(cities, countries);
    // Main.MostPopulatedCounteryPerContinent(cities, countries);
    Main.HighestPopulatedCapitalCity(cities, countries);
  }

  public static void getHighestPopulatedCityPerCountry(List<City> cities, List<Country> countries) {
    countries.forEach(country -> {
      cities.stream()
          .filter(city -> city.countryCode.equals(country.code))
          .max((a, b) -> Integer.compare(a.population, b.population))
          .ifPresent(city -> System.out.println(
              country.name + " -> " +
                  city.name + " (" + city.population + ")"));
    });
  }

  public static void MostPopulatedCounteryPerContinent(List<City> cities, List<Country> countries) {
    List<String> continents = countries.stream().map(country -> country.continent).distinct().toList();
    continents.forEach(cont -> {
      countries
          .stream()
          .filter(country -> country.continent.equals(cont)).max((a, b) -> Integer.compare(a.population, b.population))
          .ifPresent(country -> System.out
              .println("continent: " + country.continent + " -> " + country.name + " " + country.population));
      ;
    });

  }

  public static void HighestPopulatedCapitalCity(List<City> cities, List<Country> countries) {
    countries.stream()
        .map(country -> {
          return cities.stream()
              .filter(city -> city.id == country.capital);
        }).map(optional -> optional.findFirst().orElse(null)).filter(f -> f != null)
        .max((a, b) -> Integer.compare(a.population, b.population))
        .ifPresent(city -> System.out.println("City: " + city.name + " Code: " + city.countryCode));
  }
}

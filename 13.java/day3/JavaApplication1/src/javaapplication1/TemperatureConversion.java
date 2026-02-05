package javaapplication1;
import java.util.function.Function;


/**
 *
 * @author miles
 */
public class TemperatureConversion implements Function<Float , Float>{

   @Override
   public Float apply(Float c){
    return 32+(1.82F * c);
   }
}

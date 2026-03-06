<script setup>
import { computed } from "vue";

const props = defineProps({
  product: Object
})

const HasDiscount = computed( () => {
  return props.product.discount > 0;
})

const priceAfterDiscount = computed(() => {
  return (props.product.price - (( props.product.price / 100) * props.product.discount))
});

const badgeColorCustimizer = ((tag) => {
  if(tag=="Fashion"){
  return "badge-accent";
  }else if(tag=="Casual"){
  return "badge-info";
  }else if(tag=="Sport"){
  return "badge-primary";
  }else{
  return "badge-success";
  }

});
</script>

<template>

<div class="card card-side bg-base-300 shadow-sm mx-3 my-3">
  <figure>
    <img
        class="px-6 py-6"
        :src="product.image"
       alt="product image" />
  </figure>
  <div class="card-body">
    <h1 class="card-title font-bold">{{product.name}}</h1> 
    <div v-if="product.badge" class="badge badge-primary badge-soft">{{product.badge}}</div>
    <br>
    <h3 class="font-bold">Description</h3>
    <p>{{product.description}}</p>
    <br><br>
    <div v-if="HasDiscount">
        <pre class="font-bold text-xl"> <del class="text-base-content/50 text-error">{{product.price}}</del> {{priceAfterDiscount}}$</pre>
    </div>
    <div v-else class="font-bold text-xl">{{product.price}} $</div>

      <div class="card-actions ">
       <button class="btn btn-primary px-7">Buy</button>
      </div>
    <div class="flex flex-wrap gap-2 mt-3">
      <div v-for="tag in product.tags" class="badge inline-block" :class="badgeColorCustimizer(tag)">{{tag}}</div>
    </div>

      </div>
</div>
</template>

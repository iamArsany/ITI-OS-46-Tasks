<script setup>
import { ref, watch } from 'vue'
import { useRoute } from 'vue-router'
import MainProduct from '@/components/MainProduct.vue'
import RelatedProducts from '@/components/RelatedProducts.vue'

const props = defineProps({
  products: Array,
});

const emit = defineEmits(['buy']);

const route = useRoute();
()=>{conosle.log("this is the route:",route)}
const selectedProductId = ref(Number(route.params.id));

watch(
  () => route.params.id,
  (newId) => {
    selectedProductId.value = Number(newId);
  }
);
</script>

<template>
  <MainProduct
    :products="products"
    :productId="selectedProductId"
    @buy="emit('buy', $event)"
  />

  <article class="prose prose-neutral ml-3">
    <h1 class="text-info text-2xl">Related Products</h1>
  </article>

  <RelatedProducts
    :products="products"
    :selectedProductId="selectedProductId"
  />
</template>

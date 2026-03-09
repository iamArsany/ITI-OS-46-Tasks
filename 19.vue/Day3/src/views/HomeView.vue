<script setup>
import NavBar from '@/components/NavBar.vue'
import MyFooter from '@/components/MyFooter.vue'
import MainProduct from '@/components/MainProduct.vue'
import RelatedProducts from '@/components/RelatedProducts.vue'


const props = defineProps({
  products: Array,
})


</script>


<template>
  <div class="text-2xl justify-center items-center text-center mt-7"> Home Page</div>
  <RelatedProducts :products="products"/>
</template>

<script setup>
  const props = defineProps({
  relatedProducts:Object
  })
</script>

<template>
<div>
<article class="prose prose-neutral ml-3">
  <h1 class="text-info text-2xl">Related Products</h1>
</article>
</div>
<div class="carousel carousel-center  rounded-box space-x-4 p-4 w-full mb-10">
  <div v-for="rProduct in relatedProducts" class="card carousel-item ">
    <div class="card-title">{{rProduct.name}}</div>
    <img
      :src="rProduct.image"
      class="rounded-box" />
  </div>
  </div>
</template>

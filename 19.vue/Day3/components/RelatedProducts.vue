<script setup>
import { computed } from 'vue'

const props = defineProps({
  products: Array,
  selectedProductId: Number,
});

const relatedProducts = computed(() =>
  props.products.filter((p) => p.id !== props.selectedProductId)
);
</script>

<template>
  <div class="flex flex-wrap gap-4 mx-3 my-3">
    <RouterLink
      v-for="product in relatedProducts"
      :key="product.id"
      :to="'/product/' + product.id"
      class="card bg-base-300 shadow-sm w-48 cursor-pointer hover:shadow-lg transition-shadow"
    >
      <figure>
        <img class="px-3 py-3 h-32 object-cover" :src="product.image" :alt="product.name" />
      </figure>
      <div class="card-body p-3">
        <h2 class="card-title text-sm">{{ product.name }}</h2>
        <p class="text-sm font-bold">
          {{ product.discount > 0
              ? (product.price - (product.price / 100) * product.discount).toFixed(0)
              : product.price }}$
          <span v-if="product.discount > 0" class="text-xs text-error line-through ml-1">
            {{ product.price }}$
          </span>
        </p>
        <span
          class="badge badge-sm text-black"
          :class="product.stock === 0 ? 'bg-red-300' : 'bg-green-300'"
        >
          Stock: {{ product.stock }}
        </span>
      </div>
    </RouterLink>
  </div>
</template>

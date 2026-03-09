<script setup>
import { computed } from "vue";

const props = defineProps({
  products: Array,
  productId: Number
});

const emit = defineEmits(["buy"]); 

const product = computed(() =>
  props.products.find((p) => p.id === props.productId)
);

const HasDiscount = computed(() => product.value?.discount > 0);

const priceAfterDiscount = computed(() =>
  product.value.price - (product.value.price / 100) * product.value.discount
);

const badgeColorCustimizer = (tag) => {
  if (tag === "Fashion") return "badge-accent";
  if (tag === "Casual")  return "badge-info";
  if (tag === "Sport")   return "badge-primary";
  return "badge-success";
};

const isOutOfStock = computed(() => product.value?.stock === 0); 

const buyProduct = () => {
  if (!isOutOfStock.value) {
    emit("buy", product.value.id); 
  }
};
</script>

<template>
  <div v-if="product" class="card card-side bg-base-300 shadow-sm mx-3 my-3">
    <figure>
      <img class="px-6 py-6" :src="product.image" alt="product image" />
    </figure>

    <div class="card-body">
      <h1 class="card-title font-bold">{{ product.name }}</h1>

      <div v-if="product.badge" class="badge badge-primary badge-soft">
        {{ product.badge }}
      </div>

      <br />
      <p>{{ product.description }}</p>

      <div class="flex flex-wrap gap-2 mt-3">
        <div
          v-for="tag in product.tags"
          :key="tag"
          class="badge inline-block"
          :class="badgeColorCustimizer(tag)"
        >
          {{ tag }}
        </div>
      </div>

      <div v-if="HasDiscount">
        <br /><br />
        <pre class="font-bold text-xl">
<del class="text-base-content/50 text-error">{{ product.price }}</del>
{{ priceAfterDiscount }}$
        </pre>
      </div>
      <div v-else class="font-bold text-xl">{{ product.price }} $</div>

      <div class="mt-1">
        <span
          class="badge badge-sm text-black"
          :class="isOutOfStock ? 'bg-red-300' : 'bg-green-300'"
        >
          Stock: {{ product.stock }}
        </span>
      </div>

      <div class="card-actions">
        <button
          class="btn btn-primary px-7"
          :disabled="isOutOfStock"
          :class="{ 'btn-disabled': isOutOfStock }"
          @click="buyProduct"
        >
          {{ isOutOfStock ? 'Out of Stock' : 'Buy' }}
        </button>
      </div>
    </div>
  </div>
</template>

<script setup>
import NavBar from '@/components/NavBar.vue'
import MyFooter from '@/components/MyFooter.vue'
import { ref } from "vue";

const ProductsData = ref([
  {
    id: 1, name: "Cozy Sneakers",
    description: "High-quality sneakers that go with everything you wear.",
    image: "https://image-cdn.hypb.st/https%3A%2F%2Fs3.store.hypebeast.com%2Fmedia%2Fimage%2F58%2Fe4%2FShoes-1-1-9f1fd.jpg?fit=max&w=320&q=90",
    badge: "NEW", price: 120, discount: 20, stock: 20,
    tags: ["Fashion", "Casual", "Sport", "test"]
  },
  { id: 2, name: "Running Shoes",  price: 90,  discount: 10, stock: 20, image: "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRpnyg5PNBo9_3orqwhIGT2bHwT73jzn88lcQ&s" },
  { id: 3, name: "Casual Boots",   price: 150, discount: 0,  stock: 20, image: "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRpnyg5PNBo9_3orqwhIGT2bHwT73jzn88lcQ&s" },
  { id: 4, name: "Flip Flops",     price: 30,  discount: 50, stock: 20, image: "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRpnyg5PNBo9_3orqwhIGT2bHwT73jzn88lcQ&s" }
]);

const selectedProductId = ref(1); 

const handleBuy = (productId) => {
  const product = ProductsData.value.find(p => p.id === productId);
  if (product && product.stock > 0) {
    product.stock--;
  }
};

const handleSelectProduct = (productId) => {
  selectedProductId.value = productId;
};
</script>

<template>
  <NavBar />
  <RouterView
    :products="ProductsData"
    :selectedProductId="selectedProductId"
    @buy="handleBuy"
    @selectProduct="handleSelectProduct"
  />
  <MyFooter />
</template>

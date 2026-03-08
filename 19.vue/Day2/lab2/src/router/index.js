import { createWebHistory, createRouter } from "vue-router";
import HomeView from "@/views/HomeView.vue";

const routes = [
  {
    path: "/",
    name: "home",
    component: HomeView,
  },
  {
    path: "/about",
    name: "about",
    component: () => import("@/views/AboutView.vue"),
  },
  {
    path: "/product/:id",
    name: "products",
    component: () => import("@/views/ProductView.vue"),
  },
];
const router = createRouter({
  history: createWebHistory(),
  routes,
});

export default router;

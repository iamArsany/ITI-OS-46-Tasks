<x-layout>
    <x-slot:title>
        Edit Post
        </x-slot>

        <div class="max-w-3xl mx-auto">
            <div class="bg-white rounded-lg shadow overflow-hidden">

                <div class="px-6 py-4 border-b border-gray-200">
                    <h2 class="text-xl font-semibold text-gray-800">
                        Edit Post
                    </h2>
                </div>

                <div class="px-6 py-4">

                    <form method="POST" action="{{ route('posts.update', $post['id']) }}">
                        @csrf
                        @method('PUT')

                        <!-- TITLE -->
                        <div class="mb-4">
                            <label for="title" class="block text-sm font-medium text-gray-700 mb-1">
                                Title
                            </label>

                            <input
                                type="text"
                                id="title"
                                name="title"
                                value="{{ $post['title'] }}"
                                class="w-full rounded-md border-gray-300 shadow-sm focus:border-blue-500 focus:ring focus:ring-blue-200 focus:ring-opacity-50 py-2 px-3 border">
                        </div>

                        <!-- DESCRIPTION -->
                        <div class="mb-4">
                            <label for="description" class="block text-sm font-medium text-gray-700 mb-1">
                                Description
                            </label>

                            <textarea
                                id="description"
                                name="description"
                                rows="5"
                                class="w-full rounded-md border-gray-300 shadow-sm focus:border-blue-500 focus:ring focus:ring-blue-200 focus:ring-opacity-50 py-2 px-3 border">{{ $post['description'] }}</textarea>
                        </div>

                        <!-- CREATOR -->
                        <div class="mb-6">
                            <label for="creator" class="block text-sm font-medium text-gray-700 mb-1">
                                Post Creator
                            </label>

                            <select
                                id="creator"
                                name="creator"
                                class="w-full rounded-md border-gray-300 shadow-sm focus:border-blue-500 focus:ring focus:ring-blue-200 focus:ring-opacity-50 py-2 px-3 border bg-white">
                                <option value="1" {{ $post['creator']['name'] == 'Ahmed' ? 'selected' : '' }}>
                                    Ahmed
                                </option>

                                <option value="2" {{ $post['creator']['name'] == 'Mohamed' ? 'selected' : '' }}>
                                    Mohamed
                                </option>

                                <option value="3" {{ $post['creator']['name'] == 'Ali' ? 'selected' : '' }}>
                                    Ali
                                </option>
                            </select>
                        </div>

                        <!-- SUBMIT -->
                        <div class="flex justify-end">
                            <button
                                type="submit"
                                class="px-4 py-2 bg-blue-600 text-white font-medium rounded-md hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500 hover:cursor-pointer">
                                Update Post
                            </button>
                        </div>

                    </form>

                </div>
            </div>
        </div>
</x-layout>
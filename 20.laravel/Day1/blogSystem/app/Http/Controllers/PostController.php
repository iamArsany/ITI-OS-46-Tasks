<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class PostController extends Controller
{
    private $posts = [
        [
            'id' => 1,
            'title' => 'first post',
            'description' => 'some description',
            'created_at' => '2026-03-11 10:00:00',
            'creator' => ['id' => 1, 'name' => 'Ahmed', 'email' => 'ahmed@gmail.com']
        ],
        [
            'id' => 2,
            'title' => 'second post',
            'description' => 'some description 2',
            'created_at' => '2026-03-11 10:00:00',
            'creator' => ['id' => 2, 'name' => 'Mohamed', 'email' => 'mohamed@gmail.com']
        ],
        [
            'id' => 3,
            'title' => 'third post',
            'description' => 'some description 2',
            'created_at' => '2026-03-11 10:00:00',
            'creator' => ['id' => 3, 'name' => 'Ali', 'email' => 'ali@gmail.com']
        ]
    ];
    private $creators = [
        1 => ['name' => 'Ahmed', 'email' => 'ahmed@gmail.com'],
        2 => ['name' => 'Mohamed', 'email' => 'mohamed@gmail.com'],
        3 => ['name' => 'Ali', 'email' => 'ali@gmail.com']
    ];
    /**
     * Helper to get posts from session or default array
     */
    private function getPosts()
    {
        if (!session()->has('posts')) {
            session(['posts' => $this->posts]);
        }
        return session('posts');
    }

    public function index()
    {
        return view('posts.index', [
            'posts' => $this->getPosts()
        ]);
    }

    public function show($id)
    {
        $posts = $this->getPosts();
        $post = collect($posts)->firstWhere('id', $id);

        if (!$post) abort(404);
        return view('posts.show', ['post' => $post]);
    }

    public function create()
    {
        return view('posts.create');
    }

    public function store(Request $request)
    {
        $posts = $this->getPosts();

        $creatorId = $request->creator;

        $creator = [
            'id' => $creatorId,
            'name' => $this->creators[$creatorId]['name'],
            'email' => $this->creators[$creatorId]['email']
        ];

        $newPost = [
            'id' => count($posts) > 0 ? max(array_column($posts, 'id')) + 1 : 1,
            'title' => $request->title,
            'description' => $request->description,
            'created_at' => now()->toDateTimeString(),
            'creator' => $creator
        ];

        $posts[] = $newPost;

        session(['posts' => $posts]);

        return to_route('posts.index');
    }

    public function edit($id)
    {
        $posts = $this->getPosts();
        $post = collect($posts)->firstWhere('id', $id);

        if (!$post) abort(404);

        return view('posts.edit', ['post' => $post]);
    }

    public function update(Request $request, $id)
    {
        $posts = $this->getPosts();

        foreach ($posts as $key => $post) {

            if ($post['id'] == $id) {

                $posts[$key]['title'] = $request->title;
                $posts[$key]['description'] = $request->description;

                $creatorId = $request->creator;

                $posts[$key]['creator'] = [
                    'id' => $creatorId,
                    'name' => $this->creators[$creatorId]['name'],
                    'email' => $this->creators[$creatorId]['email']
                ];

                break;
            }
        }

        session(['posts' => $posts]);

        return to_route('posts.index');
    }

    public function destroy($id)
    {
        $posts = $this->getPosts();

        $filteredPosts = array_filter($posts, function ($post) use ($id) {
            return $post['id'] != $id;
        });

        session(['posts' => array_values($filteredPosts)]);

        return to_route('posts.index');
    }
}

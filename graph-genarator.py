import matplotlib.pyplot as plt

# データセットサイズ
x = [10_000, 50_000, 100_000]

# 実行時間（秒）
v0_array = [0.7542, 4.8673, 21.9382]
v1_hash_map = [0.7413, 2.3893, 5.0812]
v2_avltree = [0.7078, 2.2910, 4.8869]

# グラフ描画
plt.figure(figsize=(10, 6))
plt.plot(x, v0_array, marker='o', label='v0 (array)', linestyle='--')
plt.plot(x, v1_hash_map, marker='s', label='v1 (hash-map)', linestyle='-')
plt.plot(x, v2_avltree, marker='^', label='v2 (avltree)', linestyle='-.')

plt.title('Performance Comparison (Random Keys)')
plt.xlabel('Number of Key-Value Pairs')
plt.ylabel('Execution Time (seconds)')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()

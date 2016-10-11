package test;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Optional;
import java.util.Queue;
import java.util.Scanner;

public class Solution {

    private static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder stringBuilder = new StringBuilder();
        Queue<Optional<TreeNode>> queue = new ArrayDeque<>();
        queue.add(Optional.ofNullable(root));
        while (!queue.isEmpty()) {
            Optional<TreeNode> subRoot = queue.poll();
            if (subRoot.isPresent()) {
                stringBuilder.append(subRoot.get().val);
            } else {
                stringBuilder.append("null");
            }
            stringBuilder.append(',');
            subRoot.ifPresent(r -> {
                queue.add(Optional.ofNullable(r.left));
                queue.add(Optional.ofNullable(r.right));
            });
        }
        stringBuilder.setLength(stringBuilder.length()-1);
        return stringBuilder.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.isEmpty()) {
            return null;
        }
        Scanner scanner = new Scanner(data).useDelimiter(",");
        String token = scanner.next();
        TreeNode root = fromString(token);
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode subRoot = queue.poll();
            if (!scanner.hasNext()) {
                break;
            }
            token = scanner.next();
            subRoot.left = fromString(token);
            token = scanner.next();
            subRoot.right = fromString(token);
            if (subRoot.left != null) {
                queue.add(subRoot.left);
            }
            if (subRoot.right != null) {
                queue.add(subRoot.right);
            }
        }
        return root;
    }

    private TreeNode fromString(String s) {
        if (s.equals("null")) {
            return null;
        } else {
            return new TreeNode(Integer.parseInt(s));
        }
    }

    public static void main(String[] args) {

        Solution solution = new Solution();
        String s = "1,2,3,null,null,null,null";
        TreeNode root = solution.deserialize(s);
        System.out.println(solution.serialize(root));
    }
}
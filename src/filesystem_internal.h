#pragma once
#ifndef __FILESYSTEM_INT_H__
#define __FILESYSTEM_INT_H__

#include "CRT/CRT.h"

namespace std
{
	namespace filesystem
	{
		// 30.11.7, paths
		class path;

		// 30.11.7.6, path non-member functions
		void swap(path& lhs, path& rhs) __CRT_NOEXCEPT;
		size_t hash_value(const path& p) __CRT_NOEXCEPT;

		bool operator==(const path& lhs, const path& rhs) __CRT_NOEXCEPT;
		bool operator!=(const path& lhs, const path& rhs) __CRT_NOEXCEPT;
		bool operator< (const path& lhs, const path& rhs) __CRT_NOEXCEPT;
		bool operator<=(const path& lhs, const path& rhs) __CRT_NOEXCEPT;
		bool operator> (const path& lhs, const path& rhs) __CRT_NOEXCEPT;
		bool operator>=(const path& lhs, const path& rhs) __CRT_NOEXCEPT;
		
		path operator/ (const path& lhs, const path& rhs);
		
		// 30.11.7.6.1, path inserter and extractor
		template<class charT, class traits>
		basic_ostream<charT, traits>&
		operator<<(basic_ostream<charT, traits>& os, const path& p);
		
		template<class charT, class traits>
		basic_istream<charT, traits>&
		operator>>(basic_istream<charT, traits>& is, path& p);

		// 30.11.7.6.2, path factory functions
		template<class Source>
		path u8path(const Source& source);
		template<class InputIterator>
		path u8path(InputIterator first, InputIterator last);

		// 30.11.8, filesystem errors
		class filesystem_error;

		// 30.11.11, directory entries
		class directory_entry;

		// 30.11.12, directory iterators
		class directory_iterator;

		// 30.11.12.2, range access for directory iterators
		directory_iterator begin(directory_iterator iter) __CRT_NOEXCEPT;
		directory_iterator end(const directory_iterator&) __CRT_NOEXCEPT;

		// 30.11.13, recursive directory iterators
		class recursive_directory_iterator;

		// 30.11.13.2, range access for recursive directory iterators
		recursive_directory_iterator begin(recursive_directory_iterator iter) __CRT_NOEXCEPT;
		recursive_directory_iterator end(const recursive_directory_iterator&) __CRT_NOEXCEPT;

		// 30.11.10, file status
		class file_status;
		struct space_info {
		uintmax_t capacity;
		uintmax_t free;
		uintmax_t available;
		};

		// 30.11.9, enumerations
		enum class file_type;
		enum class perms;
		enum class perm_options;
		enum class copy_options;
		enum class directory_options;
		using file_time_type = chrono::time_point<trivial-clock >;

		// 30.11.14, filesystem operations
		path absolute(const path& p);
		path absolute(const path& p, error_code& ec);

		path canonical(const path& p);
		path canonical(const path& p, error_code& ec);

		void copy(const path& from, const path& to);
		void copy(const path& from, const path& to, error_code& ec) __CRT_NOEXCEPT;
		void copy(const path& from, const path& to, copy_options options);
		void copy(const path& from, const path& to, copy_options options,
		error_code& ec) __CRT_NOEXCEPT;

		bool copy_file(const path& from, const path& to);
		bool copy_file(const path& from, const path& to, error_code& ec) __CRT_NOEXCEPT;
		bool copy_file(const path& from, const path& to, copy_options option);
		bool copy_file(const path& from, const path& to, copy_options option,
		error_code& ec) __CRT_NOEXCEPT;

		void copy_symlink(const path& existing_symlink, const path& new_symlink);
		void copy_symlink(const path& existing_symlink, const path& new_symlink,
		error_code& ec) __CRT_NOEXCEPT;

		bool create_directories(const path& p);
		bool create_directories(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool create_directory(const path& p);
		bool create_directory(const path& p, error_code& ec) __CRT_NOEXCEPT;
		bool create_directory(const path& p, const path& attributes);
		bool create_directory(const path& p, const path& attributes,
		error_code& ec) __CRT_NOEXCEPT;

		void create_directory_symlink(const path& to, const path& new_symlink);
		void create_directory_symlink(const path& to, const path& new_symlink,
		error_code& ec) __CRT_NOEXCEPT;

		void create_hard_link(const path& to, const path& new_hard_link);
		void create_hard_link(const path& to, const path& new_hard_link,
		error_code& ec) __CRT_NOEXCEPT;

		void create_symlink(const path& to, const path& new_symlink);
		void create_symlink(const path& to, const path& new_symlink,
		error_code& ec) __CRT_NOEXCEPT;

		path current_path();
		path current_path(error_code& ec);
		void current_path(const path& p);
		void current_path(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool equivalent(const path& p1, const path& p2);
		bool equivalent(const path& p1, const path& p2, error_code& ec) __CRT_NOEXCEPT;

		bool exists(file_status s) __CRT_NOEXCEPT;
		bool exists(const path& p);
		bool exists(const path& p, error_code& ec) __CRT_NOEXCEPT;

		uintmax_t file_size(const path& p);
		uintmax_t file_size(const path& p, error_code& ec) __CRT_NOEXCEPT;

		uintmax_t hard_link_count(const path& p);
		uintmax_t hard_link_count(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool is_block_file(file_status s) __CRT_NOEXCEPT;
		bool is_block_file(const path& p);
		bool is_block_file(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool is_character_file(file_status s) __CRT_NOEXCEPT;
		bool is_character_file(const path& p);
		bool is_character_file(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool is_directory(file_status s) __CRT_NOEXCEPT;
		bool is_directory(const path& p);
		bool is_directory(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool is_empty(const path& p);
		bool is_empty(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool is_fifo(file_status s) __CRT_NOEXCEPT;
		bool is_fifo(const path& p);
		bool is_fifo(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool is_other(file_status s) __CRT_NOEXCEPT;
		bool is_other(const path& p);
		bool is_other(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool is_regular_file(file_status s) __CRT_NOEXCEPT;
		bool is_regular_file(const path& p);
		bool is_regular_file(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool is_socket(file_status s) __CRT_NOEXCEPT;
		bool is_socket(const path& p);
		bool is_socket(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool is_symlink(file_status s) __CRT_NOEXCEPT;
		bool is_symlink(const path& p);
		bool is_symlink(const path& p, error_code& ec) __CRT_NOEXCEPT;

		file_time_type last_write_time(const path& p);
		file_time_type last_write_time(const path& p, error_code& ec) __CRT_NOEXCEPT;

		void last_write_time(const path& p, file_time_type new_time);
		void last_write_time(const path& p, file_time_type new_time,
		error_code& ec) __CRT_NOEXCEPT;

		void permissions(const path& p, perms prms, perm_options opts=perm_options::replace);
		void permissions(const path& p, perms prms, error_code& ec) __CRT_NOEXCEPT;
		void permissions(const path& p, perms prms, perm_options opts, error_code& ec);

		path proximate(const path& p, error_code& ec);
		path proximate(const path& p, const path& base = current_path());
		path proximate(const path& p, const path& base, error_code& ec);

		path read_symlink(const path& p);
		path read_symlink(const path& p, error_code& ec);

		path relative(const path& p, error_code& ec);
		path relative(const path& p, const path& base = current_path());
		path relative(const path& p, const path& base, error_code& ec);

		bool remove(const path& p);
		bool remove(const path& p, error_code& ec) __CRT_NOEXCEPT;

		uintmax_t remove_all(const path& p);
		uintmax_t remove_all(const path& p, error_code& ec) __CRT_NOEXCEPT;

		void rename(const path& from, const path& to);
		void rename(const path& from, const path& to, error_code& ec) __CRT_NOEXCEPT;

		void resize_file(const path& p, uintmax_t size);
		void resize_file(const path& p, uintmax_t size, error_code& ec) __CRT_NOEXCEPT;

		space_info space(const path& p);
		space_info space(const path& p, error_code& ec) __CRT_NOEXCEPT;

		file_status status(const path& p);
		file_status status(const path& p, error_code& ec) __CRT_NOEXCEPT;

		bool status_known(file_status s) __CRT_NOEXCEPT;

		file_status symlink_status(const path& p);
		file_status symlink_status(const path& p, error_code& ec) __CRT_NOEXCEPT;

		path temp_directory_path();
		path temp_directory_path(error_code& ec);

		path weakly_canonical(const path& p);
		path weakly_canonical(const path& p, error_code& ec);
	}
}


#endif